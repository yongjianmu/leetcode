#include "../../include/header.h"

class Solution
{
public:
    int maxBag(vector<int> values, vector<int> weights, int bag_weight)
    {
        int row = values.size();
        vector<vector<int> > dp(row, vector<int>(bag_weight + 1, 0));

        for(int i = 1; i <= bag_weight; ++i)
        {
            for(int j = 0; j < row; ++j)
            {
                if(weights[j] > i) // heavier than current weight
                {
                    if(0 == j)
                    {
                        dp[j][i] = 0;
                    }
                    else
                    {
                        dp[j][i] = dp[j - 1][i];
                    }
                }
                else
                {
                    if(0 == j)
                    {
                        dp[j][i] = values[j];
                        continue;
                    }
                    else
                    {
                        int previous = 0;
                        if(i - weights[j] >= 0)
                        {
                            previous = dp[j - 1][i - weights[j]] + values[j];
                        }
                        dp[j][i] = max(dp[j - 1][i], previous);
                    }
                }
            }
        }
        return dp[row - 1][bag_weight];
    }
};

int main()
{
    vector<int> values = {6,3,5,4,6};
    vector<int> weights = {2,2,6,5,4};
    int bag_weight = 10;
    Solution sol;
    int result = sol.maxBag(values, weights, bag_weight);
    printResult();
    cout << result << endl;

    return 0;
}
