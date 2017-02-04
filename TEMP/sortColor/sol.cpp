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

void sortColorOptimize(vector<int>& nums)
{
    int n = nums.size();
    if(1 >= n) return;

    // Parse red
    int non_red_start = 0;
    while(non_red_start < n && 0 == nums[non_red_start]) ++non_red_start;
    int i = non_red_start + 1;
    while(non_red_start < n)
    {
        int non_red_end = non_red_start;
        while(non_red_end < n && 0 != nums[non_red_end]) ++non_red_end;
        if(non_red_end >= n) break;
        for(i = non_red_end; i < n; ++i)
        {
            if(0 != nums[i]) break;
        }

        int non_red_len = non_red_end - non_red_start;
        int red_len = i - non_red_end;
        int swap_len = min(non_red_len, red_len);
        for(int j = i - swap_len; j < i; ++j)
        {
            swap(nums[non_red_start++], nums[j]);
        }
        if(red_len > non_red_len) non_red_start = i - 1;
    }
    
    cout << "last non red" << non_red_start << endl;
    printVector1D(nums);

    // Parse blue
    int non_blue_end = n - 1;
    while(non_blue_end >= non_red_start && 2 == nums[non_blue_end]) --non_blue_end;
    i = non_blue_end - 1;
    while(non_blue_end >= non_red_start)
    {
        int non_blue_start = non_blue_end;
        while(non_blue_start >= non_red_start && 2 != nums[non_blue_start]) --non_blue_start;
        if(non_blue_start < non_red_start) break;
        for(i = non_blue_start; i >= non_red_start; --i)
        {
            if(2 != nums[i]) break;
        }

        int non_blue_len = non_blue_end - non_blue_start;
        int blue_len = non_blue_start - i;
        int swap_len = min(non_blue_len, blue_len);
        for(int j = i + swap_len; j > i; --j)
        {
            swap(nums[non_blue_end--], nums[j]);
        }
        if(blue_len > non_blue_len) non_blue_end = i + 1;
    }
}

int main()
{
    vector<int> input = {1,1,1,0,1,1,0,0,2,0,0,1,1,2,1,1,1,2,0,0,2,0,2,1,1,0,1,0,0,1,0,2,1,2,2,2,1,0};
    //vector<int> input = {1,2,1,0,0,0,0};
    //vector<int> input = {2,0,0,0,0,1,2,2};
    sortColorOptimize(input);
    printResult();
    printVector1D(input);

    return 0;
}
