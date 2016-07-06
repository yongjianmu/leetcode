#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(1 == size || 0 == size)
        {
            return true;
        }

        int max_jump = 0;
        for(int i = 0; i < size; ++i)
        {
            --max_jump;

            max_jump = max(max_jump, nums[i]);

            if(0 >= max_jump)
            {
                return false;
            }

            if(max_jump + i >= size - 1)
            {
                return true;
            }
        }

        return false;
    }
};
