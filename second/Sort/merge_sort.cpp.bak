#include "../include/header.h"

class Solution {
public:
    void merge(int start, int mid, int end, vector<int>& nums, vector<int>& tmp)
    {
        for(int i = 0; i < end; ++i)
        {
            tmp[i] = nums[i];
        }

        int i, j, k;
        for(i = start, j = mid, k = start; i < mid && j < end; ++k)
        {
            if(tmp[i] < tmp[j])
            {
                nums[k] = tmp[i++];
            }
            else
            {
                nums[k] = tmp[j++];
            }
        }
        while(i < mid)
        {
            nums[k++] = tmp[i++];
        }
        while(j < end)
        {
            nums[k++] = tmp[j++];
        }
    }

    void mergeSort(int start, int end, vector<int>& nums, vector<int>& tmp) 
    {
        if (start < end - 1)
        {
            int mid = start + ((end - start) >> 1);
            mergeSort(start, mid, nums, tmp);
            mergeSort(mid, end, nums, tmp);
            merge(start, mid, end, nums, tmp);
        }
    }

    void sortColors(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int size = nums.size();
        if(1 >= size)
        {
            return;
        }

        int start = 0, end = size;
        vector<int> tmp(size, 0);
        mergeSort(start, end, nums, tmp);
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 0};
    Solution sol;
    sol.sortColors(input);
    printVector1D(input);
    return 0;
}
