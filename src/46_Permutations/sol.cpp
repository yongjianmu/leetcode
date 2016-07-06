#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool nextPermute(vector<int>& nums)
    {
        int k = -1;
        for(int i = nums.size() - 2; i >= 0; --i)
        {
            if(nums[i] < nums[i + 1])
            {
                k = i;
                break;
            }
        }

        if(-1 == k)
        {
            return false;
        }

        int l = nums.size() - 1;
        for(int j = nums.size() - 1; j > k; --j)
        {
            if(nums[k] < nums[j])
            {
                l = j;
                break;
            }
        }

        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());

        return true;
    }


    vector<vector<int> > permute(vector<int>& nums) {
        vector<vector<int> > ret;
        int size = nums.size();
        if(1 > size)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());

        do
        {
            ret.push_back(nums);
        }
        while(nextPermute(nums));

        return ret;
    }
};


int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    Solution sol;

    vector<vector<int> > ret = sol.permute(input);
    for(int i = 0; i < ret.size(); ++i)
    {
        for(int j = 0; j < ret[i].size(); ++j)
        {
            cout << ret[i][j] << ",";
        }
        cout << endl;
    }

    return 0;
}
