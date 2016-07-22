#include "../include/header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        int size = nums.size();
        if(1 >= size)
        {
            return;
        }

        int zero = 0, one = 0, two = 0;
        for(int i = 0; i < size; ++i)
        {
            switch(nums[i])
            {
                case 0:
                    ++zero;
                    break;
                case 1:
                    ++one;
                    break;
                case 2:
                    ++two;
                    break;
                default:
                    break;
            }
        }
        for(int i = 0; i < size; ++i)
        {
            if(0 != zero)
            {
                nums[i] = 0;
                zero--;
            }
            else if(0 != one)
            {
                nums[i] = 1;
                one--;
            }
            else if(0 != two)
            {
                nums[i] = 2;
                two--;
            }
        }
    }
};

int main()
{
    vector<int> input = {1, 2, 1, 0};
    Solution sol;
    sol.sortColors(input);
    printVector1D(input);
    return 0;
}
