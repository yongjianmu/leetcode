#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


/*
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
*/


class Solution {
public:

    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        if(nums.size() == 0)
        {
            return ret;
        }
        sort(nums.begin(), nums.end());
        ret = 1;
        int curr = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == nums[i - 1] + 1)
            {
                ++curr;
                ret = max(ret, curr);
            }
            else if(nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                curr = 1;
            }
        }

        return ret;
    }
};

int main()
{
    vector<int> input;
    input.push_back(100);
    input.push_back(4);
    input.push_back(200);
    input.push_back(1);
    input.push_back(3);
    input.push_back(2);

    cout << "Result" << endl;
    Solution sol;
    cout << sol.longestConsecutive(input) << endl;
    return 0;
}
