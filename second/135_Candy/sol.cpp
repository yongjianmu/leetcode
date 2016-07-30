#include "../include/header.h"

/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int num = ratings.size();
        if(0 == num)
        {
            return 0;
        }

        vector<int> ans(num, 1);
        for(int i = 1; i < num; ++i)
        {
            if(ratings[i] > ratings[i - 1])
            {
                ans[i] = ans[i - 1] + 1;
            }
        }

        for(int i = num - 2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1] && ans[i] <= ans[i + 1])
            {
                ans[i] = ans[i + 1] + 1;
            }
        }

        return accumulate(ans.begin(), ans.end(), 0);
    }
};

int main()
{
    vector<int> input = {1,2,3,1,3,4,1,7,6,3,1,7};
    Solution sol;
    int result = sol.candy(input);
    printResult();
    cout << result << endl;

    return 0;
}
