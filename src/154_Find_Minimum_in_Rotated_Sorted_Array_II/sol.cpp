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

        for(int i = 1; i < size; ++i)
        {
            if(nums[i] < nums[i - 1])
            {
                return nums[i];
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
