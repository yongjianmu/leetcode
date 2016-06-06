#include <vector>
#include <iostream>
#include <map>
#include <climits>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int ret, old_diff = INT_MAX;
        int size = nums.size();

        if(0 >= size)
        {
            return ret;
        }
        
        sort(nums.begin(), nums.end());

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
                int diff = sum - target;
                
                if(0 == diff)
                {
                    cout << "No diff, current sum: " << sum << endl;
                    ret = sum;
                    old_diff = diff;
                    break;
                }
                else if(0 > diff)
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

                diff = diff < 0? -diff: diff;
                //cout << "current diff: " << diff << endl;
                //cout << "current sum: " << sum << endl;
                if(diff < old_diff)
                {
                    //cout << "update diff: " << diff << endl;
                    //cout << "update sum: " << sum << endl;
                    old_diff = diff;
                    ret = sum;
                }
                //cout << endl;
            }
        }

        return ret;
    }
};


int main()
{
    vector<int> input;
    input.push_back(1);
    input.push_back(1);
    input.push_back(1);
    input.push_back(0);
    int target = 100;
    
    Solution sol;
    cout << sol.threeSumClosest(input, target) << endl;

    return 0;
}
