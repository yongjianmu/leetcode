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
        int day = prices.size();
        int profit = 0;

        for(int i = 0; i < day; ++i)
        {
            int min_price = prices[i];
            while(i + 1 < day && prices[i] <= prices[i + 1])
            {
                ++i;
            }
            profit += prices[i] - min_price;
        }

        return profit;
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
