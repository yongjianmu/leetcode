#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int> > ret;
        int size = nums.size();
        if(0 >= size)
        {
            return ret;
        }

        sort(nums.begin(), nums.end());

        for(int i = 0; i < size - 3; ++i)
        {
            while(i > 0 && i < size - 3 && nums[i] == nums[i - 1])
            {
                ++i;
            }

            if(i > size - 4)
            {
                break;
            }

            for(int j = i + 1; j < size - 2; ++j)
            {
                while(j > i + 1 && j < size - 2 && nums[j] == nums[j - 1])
                {
                    ++j;
                }

                if(j > size - 3)
                {
                    break;
                }

                int left = j + 1;
                int right = size - 1;

                while(left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];

                    if(target == sum)
                    {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        ret.push_back(tmp);

                        ++left;
                        while(left < right && nums[left] == nums[left - 1])
                        {
                            ++left;
                        }

                        --right;
                        while(left < right && nums[right] == nums[right] + 1)
                        {
                            --right;
                        }
                    }
                    else if(target > sum)
                    {
                        ++left;
                        while(left < right && nums[left] == nums[left - 1])
                        {
                            ++left;
                        }
                    }
                    else 
                    {
                        --right;
                        while(left < right && nums[right] == nums[right + 1])
                        {
                            --right;
                        }
                    }
                }

            }
        }

        return ret;
    }
};

int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(-2);
    input.push_back(-5);
    input.push_back(-4);
    input.push_back(-3);
    input.push_back(3);
    input.push_back(3);
    input.push_back(5);

    int target = 0;

    Solution sol;
    vector<vector<int> >output = sol.fourSum(input, -11);
    for(int i = 0; i < output.size(); ++i)
    {
        for(int j = 0; j < output[i].size(); ++j)
        {
            cout << output[i][j] << ",";
        }
        cout << endl;
    }

}
