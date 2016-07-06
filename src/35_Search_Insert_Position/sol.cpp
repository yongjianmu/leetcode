#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int len = nums.size();
        if(0 == len)
        {
            return 0;
        }

        int left = 0;
        int right = len - 1;
        int mid = 0;
        while(left <= right)
        {
            mid = left + ((right - left) >> 1);
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                return mid;
            }
        }

        return nums[mid] < target? mid + 1: mid;
    }
};

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(3);
    int target = 2;
    Solution sol;
    cout << sol.searchInsert(input, target) << endl;
    return 0;
}
