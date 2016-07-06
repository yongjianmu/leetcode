#include "../include/header.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
        {
            if(mp.find(*iter) != mp.end())
            {
                return true;
            }
            mp[*iter] = true;
        }
        return false;
    }
};
