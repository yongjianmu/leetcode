#include <iostream>
#include <vector>

using namespace std;

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return 0;
        }
        else if(1 == size)
        {
            return nums[0];
        }

        int left = 0;
        int right = size - 1;

        while(left <= right)
        {
            int mid = (right + left) >> 1;
            if(mid > 0 && nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }

            if(mid < size - 1 && nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }

            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return nums[0];
    }
};

int main()
{
    vector<int> input = {1, 2, 0};
    Solution sol;
    cout << sol.findMin(input) << endl;

    return 0;
}
