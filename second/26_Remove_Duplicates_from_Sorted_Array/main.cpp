#include "../include/header.h"

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(0 == nums.size())
        {
            return 0;
        }

        for(auto iter = nums.begin() + 1; iter != nums.end(); )
        {
            if(*iter == *(iter - 1))
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

int main() {
    vector<int> input = {1, 1, 1, 2};
    Solution sol;
    int result = sol.removeDuplicates(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}