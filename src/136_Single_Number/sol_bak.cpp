#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:

    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); ++i)
        {
            ++mp[nums[i]];
        }

        for(unordered_map<int, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
        {
            if(1 == iter->second)
            {
                return iter->first;
            }
        }

        return -1;
    }
};
