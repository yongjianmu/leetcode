#include "../../second/include/header.h"
#include <pthread.h>

static int gCnt = 0;
void print()
{
    cout << gCnt++ << endl;
}

class Solution
{
private:
    queue<void (*)()> mQueue;
    pthread_mutex_t mMutex;
    bool mFired = false;

public:
    Solution()
    {
        pthread_mutex_init(&mMutex, NULL);
    }

    ~Solution()
    {
        pthread_mutex_destroy(&mMutex);
    }

    int lock()
    {
        return pthread_mutex_lock(&mMutex);
    }

    int unlock()
    {
        return pthread_mutex_unlock(&mMutex);
    }

    bool registerFunc(void (*func)() )
    {
        lock();
        if(mFired) 
        {
            unlock();
            func();
        }
        else
        {
            mQueue.push(func);
            unlock();
        }
        return true;
    }

    void eventFire()
    {
        while(true)
        {
            lock();
            if(!mQueue.empty())
            {
                void (*cur)() = mQueue.front();
                mQueue.pop();
                unlock();
                cur();
            }
            else
            {
                mFired = true;
                unlock();
                break;
            }
        }
    }
};

int main()
{
    Solution sol;
    sol.registerFunc(&print);
    sol.registerFunc(&print);
    sol.eventFire();
    return 0;
}
