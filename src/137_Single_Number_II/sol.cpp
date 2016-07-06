#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int size = nums.size();
        int bit[32] = {0};
        int ret = 0x0;

        for(int i = 0; i < 32; ++i)
        {
            for(int j = 0; j < size; ++j)
            {
                bit[i] += (nums[j]>>i) & 0x1;
            }
            ret |= (bit[i] % 3) << i;
        }

        return ret;
    }
};

int main()
{
    vector<int> input = {1, 2, 2, 2, 3, 3, 3};
    Solution sol;
    cout << sol.singleNumber(input) << endl;
    return 0;
}
