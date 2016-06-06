#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        vector<int>::iterator iter = nums.begin();
        for(; iter != nums.end(); )
        {
            if(val == *iter)
            {
                nums.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        return nums.size();
    }
};

int main()
{
    vector<int> input;
    input.push_back(3);
    input.push_back(2);
    input.push_back(2);
    input.push_back(3);
    int val = 2;

    Solution sol;
    cout << "Size: " << sol.removeElement(input, val) << endl;
    vector<int>::iterator iter;
    for(iter = input.begin(); iter != input.end(); ++iter)
    {
        cout << *iter << ",";
    }
    cout << endl;

    return 0;
}
