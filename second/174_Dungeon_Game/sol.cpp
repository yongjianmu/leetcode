#include "../include/header.h"


class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int row = dungeon.size();
        if(0 == row)
        {
            return 0;
        }

        int col = dungeon[0].size();
        if(0 == col)
        {
            return 0;
        }

        vector<vector<int> > dp(row, vector<int>(col, 0));
        dp[row - 1][col - 1] = -dungeon[row - 1][col - 1];
        if(0 > dp[row - 1][col - 1])
        {
            dp[row - 1][col - 1] = 0;
        }

        for(int i = row - 2; i >= 0; --i)
        {
            dp[i][col - 1] = dp[i + 1][col - 1] - dungeon[i][col - 1];
            if(0 > dp[i][col - 1])
            {
                dp[i][col - 1] = 0;
            }
        }
        for(int j = col - 2; j >= 0; --j)
        {
            dp[row - 1][j] = dp[row - 1][j + 1] - dungeon[row - 1][j];
            if(0 > dp[row - 1][j])
            {
                dp[row - 1][j] = 0;
            }
        }

        for(int i = row - 2; i >= 0; --i)
        {
            for(int j = col - 2; j >= 0; --j)
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if(0 > dp[i][j])
                {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[0][0] + 1;
    }
};

int main()
{
    vector<vector<int> > matrix = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    Solution sol;
    int result = sol.calculateMinimumHP(matrix);
    printResult();
    cout << result << endl;

    return 0;
}
