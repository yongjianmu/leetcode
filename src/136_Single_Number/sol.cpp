#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:

    int singleNumber(vector<int>& nums) {
        int ret = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            ret ^= nums[i];
        }

        return ret;
    }
};
