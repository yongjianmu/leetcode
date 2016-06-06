#include <iostream>
#include <vector>
#include <climit>

using namespace std;

class Solution {
    public:
    int jump(vector<int>& nums) {
       int size = nums.size();
       int ret = 0;
       if(0 == size || 1 == size)
       {
           return ret;
       }

       int curr_jump = 0;
       int last_jump = 0;

       for(int i = 0; i < size; ++i)
       {
           if(last_jump < i)
           {
               last_jump = curr_jump;
               ++ret;
           }

           curr_jump = curr_jump < nums[i] + i? nums[i] + i : curr_jump;
       }
       return ret;
   }
};
