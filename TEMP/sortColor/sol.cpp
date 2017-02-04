#include "../../second/include/header.h"

void sortColor(vector<int>& nums)
{
    int n = nums.size();
    if(0 == n) return;
    
    int red = 0, blue = n - 1;
    for(int i = 0; i <= blue; ++i)
    {
        if(0 == nums[i]) swap(nums[i], nums[red++]);
        else if(2 == nums[i]) swap(nums[i--], nums[blue--]);
    }
}

void sortColor2(vector<int>& nums)
{
    int n = nums.size();
    if(1 >= n) return;

    int red = 0, white = 0;
    for(int i = 0; i < n; ++i)
    {
        int v = nums[i];
        nums[i] = 2;
        if(v < 2) nums[white++] = 1;
        if(v == 0) nums[red++] = 0;
    }
}

int main()
{
    //vector<int> input = {0,0,1,2,0,1,2,0};
    vector<int> input = {1,2,0,0};
    sortColor2(input);
    printResult();
    printVector1D(input);

    return 0;
}
