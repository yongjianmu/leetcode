#include "../include/header.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int cnt = size % 2 == 0 ? (size >> 1) - 1 : (size >> 1);
        auto iterl = nums.begin() + 1;
        while(cnt > 0)
        {
            auto iterr = nums.end() - 1;
            int insert = *iterr;
            nums.erase(iterr);
            nums.insert(iterl, insert);
            ++iterl, ++iterl;
            --cnt;
        }
    }
};

int main()
{
    vector<int> input = {3, 5, 2, 1, 6, 4};
    Solution sol;
    sol.wiggleSort(input);
    printResult();
    printVector1D(input);

    return 0;
}
