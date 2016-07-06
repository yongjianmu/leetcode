#include "../include/header.h"

/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k > nums.size())
        {
            k -= nums.size();
        }

        queue<int> st;
        vector<int>::reverse_iterator riter = nums.rbegin();
        for(int i = 0; i < k; ++i)
        {
            st.push(*riter);
            ///iter = next(riter.base());
            ++riter;
            nums.erase(riter.base());
        }

        while(!st.empty())
        {
            nums.insert(nums.begin(), st.front());
            st.pop();
        }
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 7};
    Solution sol;
    sol.rotate(input, 3);
    for(int i = 0; i < input.size(); ++i)
    {
        cout << input[i] << ", ";
    }
    cout << endl;
    return 0;
}
