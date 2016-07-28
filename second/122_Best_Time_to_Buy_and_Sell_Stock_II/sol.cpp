#include "../include/header.h"


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(0 == size)
        {
            return 0;
        }

        int profit = 0, cur = 0, min_price = prices[0];
        for(int i = 1; i < size; ++i)
        {
            if(prices[i] < prices[i - 1])
            {
                profit += cur;
                cur = 0;
                min_price = prices[i];
            }
            else
            {
                if(prices[i] > min_price)
                {
                    cur = max(cur, prices[i] - min_price);
                }
            }
        }
        cout << cur << endl;
        profit += cur;
        return profit;
    }
};

int main()
{
    vector<int> input = {6, 1, 3, 2, 4, 7};
    Solution sol;
    int result = sol.maxProfit(input);
    printResult();
    cout << result << endl;

    return 0;
}
