#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binary_search(vector<int>& nums, int left, int right, int target)
    {
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
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
        return -1;
    }

    int search_recursive(vector<int>& nums, int left, int right, int target)
    {
        if(nums[left] <= nums[right])
        {
            return binary_search(nums, left, right, target);
        }

        /* nums[left] > nums[right], not an ordered array */
        int mid = left + ((right - left) >> 1);
        int tmp = search_recursive(nums, left, mid, target);
        if(-1 != tmp)
        {
            return tmp;
        }
        return search_recursive(nums, mid + 1, right, target);
    }

    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(0 == len)
        {
            return -1;
        }

        return search_recursive(nums, 0, len - 1, target);
    }
};


int main()
{
    vector<int> input;
    input.push_back(3);
    input.push_back(1);
    int target = 0;
    Solution sol;
    cout << sol.search(input, target) << endl;

    return 0;
}
