#include "../include/header.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int> > dp(row, vector<int>(col, 0));

        dp[row - 1][col - 1] = max(0 - dungeon[row - 1][col - 1], 0);
        cout << "dungeon[" << row - 1 << "][" << col - 1 << "]: " << dungeon[row - 1][col - 1] << endl;
        cout << "dp[" << row - 1 << "][" << col - 1 << "]: " << dp[row - 1][col - 1] << endl;

        // Calculate two side connected to the target
        for(int i = row - 2; i >= 0; --i)
        {
            dp[i][col - 1] = max(dp[i + 1][col - 1] - dungeon[i][col - 1], 0); // calc right side way
            cout << "dp[" << i << "][" << col - 1 << "]: " << dp[i][col - 1] << endl;
        }

        for(int j = col - 2; j >= 0; --j)
        {
            dp[row - 1][j] = max(dp[row - 1][j + 1] - dungeon[row - 1][j], 0); //calc bottom side way
            cout << "dp[" << row - 1 << "][" << j << "]: " << dp[row - 1][j] << endl;
        }

        for(int i = row - 2; i >= 0; --i)
        {
            for(int j = col - 2; j >= 0; --j)
            {
                dp[i][j] = max(min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j], 0);
            }
        }

        return dp[0][0] + 1;
    }
};

int main()
{
    vector<vector<int> > input;
    vector<int> row0 = {0, -3};
    input.push_back(row0);
    Solution sol;
    cout << sol.calculateMinimumHP(input) << endl;

    return 0;
}
