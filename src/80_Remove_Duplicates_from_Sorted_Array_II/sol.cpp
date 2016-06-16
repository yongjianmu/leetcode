#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

/*
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ret = 0;
        int size = nums.size();
        if(0 == size)
        {
            return ret;
        }

        unordered_map<int, int> mp;
        vector<int>::iterator v_iter;
        for(v_iter = nums.begin(); v_iter != nums.end(); )
        {
            if(mp.find(*v_iter) != mp.end())
            {
                if(2 > mp[*v_iter])
                {
                    ++mp[*v_iter];
                }
                else
                {
                    nums.erase(v_iter);
                    continue;
                }
            }
            else
            {
                mp[*v_iter] = 1;
            }
            ++v_iter;
        }

        unordered_map<int, int>::iterator iter;
        for(iter = mp.begin(); iter != mp.end(); ++iter)
        {
            ret += iter->second;
        }

        return ret;
    }
};

int main()
{
    vector<int> input;
    input.push_back(-1);
    input.push_back(-1);
    input.push_back(-1);
    input.push_back(0);
    input.push_back(0);
    input.push_back(3);
    input.push_back(3);

    Solution sol;
    cout << sol.removeDuplicates(input) << endl;

    vector<int>::iterator iter;
    for(iter = input.begin(); iter != input.end(); ++iter)
    {
        cout << *iter << ", ";
    }
    cout << endl;

    return 0;
}
