#include "../include/header.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(0 == size)
        {
            return 0;
        }

        int profit = 0, min_price = prices[0];
        vector<int> dp;
        for(int i = 0; i < size; ++i)
        {
            profit = max(profit, prices[i] - min_price);
            min_price = min(min_price, prices[i]);
            dp.push_back(profit);
        }

        int i = size - 1, max_profit = dp[size - 1], money = prices[size - 1];
        profit = 0;
        while(0 <= i)
        {
            profit = max(profit, money - prices[i]);
            money = max(money, prices[i]); // Reverse to find the max daily price, then minus the prices[i] to get the second max profit
            max_profit = max(max_profit, dp[i] + profit);
            --i;
        }
        return max_profit;
    }
};

int main()
{
    vector<int> input = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    Solution sol;
    int result = sol.maxProfit(input);
    printResult();
    cout << result << endl;

    return 0;
}
