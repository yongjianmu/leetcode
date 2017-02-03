#include "../../second/include/header.h"


#define HT_SIZE         64
#define a               29
#define b               23
#define HASHFUNC(X)     (((a * (X)) + b) % HT_SIZE)

struct Node
{
    int val;
    int index;
    Node(){val = 0; index = -1;}
};

class HASHMAP
{
public:
    HASHMAP()
    {
        mBucket = new Node[HT_SIZE];
        mIndex = new int[HT_SIZE];
        memset(mIndex, -1, sizeof(int) * HT_SIZE);
        mLen = -1;
    }

    void addHASH(int key, int value)
    {
        int idx = HASHFUNC(key);
        mBucket[idx].val = value;
        if(mBucket[idx].index == -1)
        {
            ++mLen;
            mIndex[mLen] = idx;
            mBucket[idx].index = mLen;
        }
    }

    void deleteHASH(int key)
    {
        int idx = HASHFUNC(key);
        if(mBucket[idx].index == -1) return;
        mIndex[mBucket[idx].index] = -1;
        mBucket[mIndex[mLen]].index = mBucket[idx].index;
        swap(mIndex[mLen], mIndex[mBucket[idx].index]);
        --mLen;
        mBucket[idx].index = -1;
    }

    void iteration()
    {
        for(int i = 0; i <= mLen; ++i)
        {
            cout << mBucket[mIndex[i]].val << endl;
        }
    }

    int lookup(int key)
    {
        if(-1 == mLen) return INT_MIN;

        int idx = HASHFUNC(key);
        return mBucket[idx].index == -1 ? INT_MIN : mBucket[idx].val;
    }

    void clearHash()
    {
        mLen = -1;
        delete[] mBucket;
        delete[] mIndex;
        mBucket = new Node[HT_SIZE];
        mIndex = new int[HT_SIZE];
        memset(mIndex, -1, sizeof(int) * HT_SIZE);
    }

private:
    Node* mBucket;
    int* mIndex;
    int mLen;
};

int main()
{
    HASHMAP hashmap;
    for(int i = 0; i < 10; ++i)
    {hashmap.addHASH(i, i);}
    hashmap.iteration();

    hashmap.deleteHASH(1);
    hashmap.iteration();

    cout << hashmap.lookup(1) << endl;
    cout << hashmap.lookup(2) << endl;
    return 0;
}
