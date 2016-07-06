#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/

class Solution {
public:
    void merge(vector<int>& nums, int start, int mid, int end)
    {
        vector<int> tmp;
        tmp.insert(tmp.begin(), nums.begin(), nums.end());
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

    void merge_sort(vector<int>& nums, int start, int end)
    {
        if(start < end - 1)
        {
            int mid = (start + end) >> 1;
            merge_sort(nums, start, mid);
            merge_sort(nums, mid, end);
            merge(nums, start, mid, end);
        }
    }

    void sortColors(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int size = nums.size();
        if(1 >= size)
        {
            return;
        }

        merge_sort(nums, 0, size);
    }
};

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(0);
    input.push_back(2);
    input.push_back(1);
    input.push_back(2);
    input.push_back(0);
    input.push_back(1);
    input.push_back(1);

    Solution sol;
    sol.sortColors(input);

    for(vector<int>::iterator iter = input.begin(); iter != input.end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl;

    return 0;
}
