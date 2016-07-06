#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        int day = prices.size();
        if(0 == day)
        {
            return ret;
        }
        int profit = 0;
        int min_price = prices[0];
        vector<int> dp;
        dp.push_back(profit);

        for(int i = 1; i < day; ++i)
        {
            profit = max(profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
            dp.push_back(profit);
        }

        ret = dp[day - 1];
        profit = 0;
        int max_price = prices[day - 1];
        for(int i = day - 1; i >= 0; --i)
        {
            profit = max(profit, max_price - prices[i]);
            max_price = max(max_price, prices[i]);
            ret = max(ret, dp[i] + profit);
        }

        return ret;
    }
};

int main()
{
    vector<int> input;
    input.push_back(7);
    input.push_back(1);
    input.push_back(5);
    input.push_back(3);
    input.push_back(6);
    input.push_back(4);

    Solution sol;
    cout << sol.maxProfit(input) << endl;

    return 0;
}
