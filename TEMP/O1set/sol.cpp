#include "../../second/include/header.h"

#define MAX_LEN     64

class O1SET
{
private:
    int* mBucket;
    int* mIndex;
    int mLen;

public:
    O1SET()
    {
        mBucket = new int[MAX_LEN];
        memset(mBucket, INT_MAX, sizeof(int) * MAX_LEN);
        mIndex = new int[MAX_LEN];
        memset(mIndex, -1, sizeof(int) * MAX_LEN);
        mLen = 0;
    }

    ~O1SET()
    {
        if(NULL != mBucket) delete[] mBucket;
        if(NULL != mIndex) delete[] mIndex;
    }

    void addSet(int key)
    {
        int idx = key % MAX_LEN;
        if(mBucket[idx] >= mLen || mIndex[mBucket[idx]] != idx)
        {
            mIndex[mLen] = idx;
            mBucket[idx] = mLen++;
        }
    }

    void deleteSet(int key)
    {
        int idx = key % MAX_LEN;
        if(mBucket[idx] >= mLen || mIndex[mBucket[idx]] != idx) return;

        mIndex[mBucket[idx]] = -1;
        mBucket[mIndex[mLen - 1]] = mBucket[idx];
        swap(mIndex[mLen - 1], mIndex[mBucket[idx]]);
        mBucket[idx] = INT_MAX;
        --mLen;
    }

    bool lookupSet(int key)
    {
        int idx = key % MAX_LEN;
        if(mBucket[idx] >= mLen || mIndex[mBucket[idx]] != idx) return false;
        return true;
    }

    void iteration()
    {
        for(int i= 0; i < mLen; ++i)
        {
            cout << mIndex[i] << endl;
        }
    }

    bool isEmpty()
    {
        return mLen > 0;
    }

    void clearSet()
    {
        mLen = 0;
    }
};

int main()
{
    O1SET hashmap;
    for(int i = 0; i < 10; ++i)
    {hashmap.addSet(i);}
    hashmap.iteration();

    hashmap.deleteSet(1);
    hashmap.iteration();

    cout << hashmap.lookupSet(1) << endl;
    cout << hashmap.lookupSet(2) << endl;

    hashmap.clearSet();
    for(int i = 10; i < 20; ++i)
    {hashmap.addSet(i);}
    hashmap.iteration();

    hashmap.deleteSet(11);
    hashmap.iteration();

    cout << hashmap.lookupSet(11) << endl;
    cout << hashmap.lookupSet(12) << endl;

    return 0;
}
