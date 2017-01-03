#include "../../include/header.h"

class Solution
{
public:
    int findMissing(vector<int> nums, int N)
    {
        int size = nums.size();
        if(0 == size || nums.back() != N)
        {
            return N;
        }

        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = left + ((right - left) >> 1);
            if(mid == nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return nums[right] - 1;
    }
};

int main()
{
    vector<int> input = {1,2,3,4,5,6,7};
    int N = 7;
    Solution sol;
    int result = sol.findMissing(input, N);
    printResult();
    cout << result << endl;

    return 0;
}
