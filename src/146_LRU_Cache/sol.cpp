#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class LRUCache{
public:
    int mCapacity;
    unordered_map<int, int> mUmap;
    vector<int> mVec;

    LRUCache(int capacity) {
        mCapacity = capacity;
    }
    
    int get(int key) {
        if(mUmap.find(key) == mUmap.end())
        {
            return -1;
        }
        else
        {
            vector<int>::iterator vec_iter = find(mVec.begin(), mVec.end(), key);
            mVec.erase(vec_iter);
            mVec.push_back(key);
            return mUmap[key];
        }
    }
    
    void set(int key, int value) {
        unordered_map<int, int>::iterator map_iter = mUmap.find(key);
        vector<int>::iterator vec_iter;
        if(map_iter != mUmap.end()) // Already exists
        {
            vec_iter = find(mVec.begin(), mVec.end(), map_iter->first);
            mVec.erase(vec_iter);
            mVec.push_back(map_iter->first);
            mUmap[key] = value;
        }
        else
        {
            if(mCapacity > mVec.size()) // Not exists, not full
            {
                mVec.push_back(key);
                mUmap[key] = value;
            }
            else                        // Not exists, full
            {
                vec_iter = mVec.begin();
                map_iter = mUmap.find(*vec_iter);
                mUmap.erase(map_iter);
                mUmap[key] = value;
                mVec.erase(vec_iter);
                mVec.push_back(key);
            }
        }
    }
};

int main()
{
    LRUCache LRU(2);
    LRU.set(2, 1);
    LRU.set(1, 1);
    LRU.get(2);
    LRU.set(4, 1);
    LRU.get(1);
    LRU.get(2);

    return 0;
}
