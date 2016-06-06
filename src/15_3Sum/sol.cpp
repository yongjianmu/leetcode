#include <vector>
#include <iostream>
#include <map>

using namespace std;


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) 
    {
        vector<vector<int> > ret;
        int size = nums.size();

        if(0 >= size)
        {
            return ret;
        }
        
        sort(nums.begin(), nums.end());
        if(0 < nums[0] || 0 > nums[size - 1])
        {
            return ret;
        }

        for(int i = 0; i < size - 2; ++i)
        {

            while(i > 0 && i < size - 2 && nums[i] == nums[i - 1])
            {
                ++i;
            }

            if(i > size - 3)
            {
                break;
            }

            int left = i + 1;
            int right = size - 1;

            while(left < right)
            {
                int sum  = nums[i] + nums[left] + nums[right];
                
                if(0 == sum)
                {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    ret.push_back(tmp);

                    ++left;
                    while(left < right && nums[left] == nums[left - 1])
                    {
                        ++left;
                    }

                    --right;
                    while(left < right && nums[right] == nums[right + 1])
                    {
                        --right;
                    }
                }
                else if(0 > sum)
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

        return ret;
    }
};


int main()
{
    vector<int> input;
    input.push_back(-3);
    input.push_back(-2);
    input.push_back(-1);
    input.push_back(0);
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(4);
    input.push_back(5);
    input.push_back(6);
    
    Solution sol;
    vector<vector<int> >output = sol.threeSum(input);
    for(int i = 0; i < output.size(); ++i)
    {
        for(int j = 0; j < output[i].size(); ++j)
        {
            cout << output[i][j] << ",";
        }
        cout << endl;
    }

    return 0;
}
