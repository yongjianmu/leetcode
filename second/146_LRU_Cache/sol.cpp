#include "../include/header.h"

class LRUCache{
public:
    unordered_map<int, int> mKey_value;
    int mCapacity;
    vector<int> mKey_vec;
    
    LRUCache(int capacity) {
        mCapacity = capacity;
    }
    
    int get(int key) {
        if(mKey_value.find(key) == mKey_value.end())
        {
            return -1;
        }
        auto iter = find(mKey_vec.begin(), mKey_vec.end(), key);
        mKey_vec.erase(iter);
        mKey_vec.insert(mKey_vec.begin(), key);
        return mKey_value[key];
    }
    
    void set(int key, int value) {
        if(mKey_value.find(key) != mKey_value.end())
        {
            auto iter = find(mKey_vec.begin(), mKey_vec.end(), key);
            mKey_vec.erase(iter);
            mKey_vec.insert(mKey_vec.begin(), key);
            mKey_value[key] = value;
        }
        else
        {
            if(mKey_vec.size() >= mCapacity)
            {
                int del_key = mKey_vec.back();
                mKey_value.erase(del_key);
                mKey_vec.pop_back();
            }
            mKey_value[key] = value;
            mKey_vec.insert(mKey_vec.begin(), key);
        }
    }
};

int main()
{
    LRUCache cache(2);
    cache.set(2,1);
    cache.set(3,2);
    cout << cache.get(3) << endl;;
    cout << cache.get(2) << endl;;
    cache.set(4,3);
    cout << cache.get(2) << endl;;
    cout << cache.get(3) << endl;;
    cout << cache.get(4) << endl;;

    return 0;
}
