#include "../../second/include/header.h"
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

static int gCnt = 0;
vector<int> get_ids()
{
    vector<int> ret(10, 0);
    for(int i = 0; i < 10; ++i)
    {
        ret[i] = gCnt++;
    }
    usleep(3000);
    return ret;
}


class Solution
{
private:
    static pthread_mutex_t mMutex;
    static queue<int> mID1;
    static queue<int> mID2;
    static pthread_cond_t mGetIDCond;
    static pthread_cond_t mSwitchCond;
    static pthread_t mGetID_tid;
    static bool mGetIDCondFlag;
    static bool mSwitchCondFlag;

    static int lock()
    {
        return pthread_mutex_lock(&mMutex);
    }

    static int unlock()
    {
        return pthread_mutex_unlock(&mMutex);
    }

    static void cleanup_function(void* a)
    {
        cout << "clean up" << endl;
    }

    static void* get_idx(void* x)
    {
        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
        pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
        pthread_cleanup_push(cleanup_function, NULL);
        while(true)
        {
            pthread_testcancel();
            lock();
            if(!mGetIDCondFlag) pthread_cond_wait(&mGetIDCond, &mMutex);
            mSwitchCondFlag = false;
            unlock();
            vector<int> vec = get_ids();
            for(auto v : vec) mID2.push(v);
            lock();
            mSwitchCondFlag = true;
            mGetIDCondFlag = false;
            unlock();
            pthread_cond_signal(&mSwitchCond);
        }
        pthread_cleanup_pop(0);
        pthread_exit(NULL);
    }

public:
    Solution()
    {
        pthread_mutex_init(&mMutex, NULL);
        pthread_cond_init(&mGetIDCond, NULL);
        pthread_cond_init(&mSwitchCond, NULL);
        vector<int> vec = get_ids();
        for(auto v : vec) mID1.push(v);
        vec = get_ids();
        for(auto v : vec) mID2.push(v);
        pthread_create(&mGetID_tid, NULL, get_idx, NULL);
        mGetIDCondFlag = false;
        mSwitchCondFlag = true;
        cout << "Construction" << endl;
    }

    ~Solution()
    {
        pthread_cancel(mGetID_tid);
        pthread_cond_broadcast(&mGetIDCond);
        pthread_join(mGetID_tid, NULL);
        pthread_cond_destroy(&mGetIDCond);
        pthread_cond_destroy(&mSwitchCond);
        pthread_mutex_destroy(&mMutex);
    }

    static int get_one_id()
    {
        int ret = 0;
        lock();
        if(mID1.empty())
        {
            if(!mSwitchCondFlag) pthread_cond_wait(&mSwitchCond, &mMutex);
            mID1.swap(mID2);
            mGetIDCondFlag = true;
            pthread_cond_signal(&mGetIDCond);
        }
        ret = mID1.front();
        mID1.pop();
        unlock();
        return ret;
    }

};

static void* printID(void* obj)
{
    Solution* sol = (Solution*) obj;
    for(int i = 0; i < 20; ++i)
    {
        usleep(1000);
        cout << sol->get_one_id() << endl;
    }
    cout << "Leave user" << endl;
    return NULL;
}

pthread_mutex_t Solution::mMutex;
queue<int> Solution::mID1;
queue<int> Solution::mID2;
pthread_cond_t Solution::mGetIDCond;
pthread_cond_t Solution::mSwitchCond;
pthread_t Solution::mGetID_tid;
bool Solution::mGetIDCondFlag;
bool Solution::mSwitchCondFlag;

int main()
{
    Solution sol;
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, printID, (void*) &sol);
    pthread_create(&tid2, NULL, printID, (void*) &sol);
    pthread_create(&tid3, NULL, printID, (void*) &sol);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
    cout << "Main func join finished" << endl;

    return 0;
}
