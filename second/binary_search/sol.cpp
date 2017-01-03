#include "../include/header.h"

int findTarget(vector<int> nums, int k)
{
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] == k)
        {
            return mid;
        }
        else if(nums[mid] > k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int findFirstNonNeg(vector<int> nums)
{
    int left = 0, right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] > 0)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return right;
}

int findFirstSmallestIndex(vector<int> nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while(left < right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] >= target)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return nums[right] == target ? right : -1;
}

int findCountsinSortedArray(vector<int>& nums, int target)
{
    int start = 0, end = 0;
    // Find end index
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    end = right;

    // Find left
    left = 0; right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] >= target) right = mid - 1;
        else left = mid + 1;
    }
    start = left;

    return end - start + 1;
}

int main()
{
    vector<int> nums = {-4,-3,-2,-1,0,0,0,0,0,1,1,1,2,3};
    int result = findCountsinSortedArray(nums, -4);
    printResult();
    cout << result << endl;
    return 0;
}
