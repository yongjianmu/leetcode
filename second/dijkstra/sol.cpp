#include "../include/header.h"

int findShortestPath(vector<vector<int> > matrix, int a, int b, string& path)
{
    int n = matrix.size();
    vector<pair<int, string> > dp(n, {INT_MAX, ""});
    dp[a] = {0, string(1, 'a' + a)};
    vector<bool> vis(n, false);
    queue<pair<int, pair<int, string> > > q;
    q.push({a, dp[a]});
    while(!q.empty())
    {
        auto node = q.front();
        q.pop();
        vis[node.first] = true;
        for(int j = 0; j < n; ++j)
        {
            if(vis[j] && (j != b)) continue;
            if(dp[j].first > node.second.first + matrix[node.first][j])
            {
                dp[j].first = node.second.first + matrix[node.first][j];
                dp[j].second = node.second.second + "->" + string(1, 'a' + j);
                if(j != b) q.push({j, dp[j]});
            }
        }
    }
    path = dp[b].second;
    return dp[b].first;
}

int main()
{
    vector<vector<int> > input = {
        {0,3,2},
        {5,0,2},
        {1,6,0}
    };
    string path;
    int result = findShortestPath(input, 2, 1, path);
    printResult();
    cout << result << ", " << path << endl;
    return 0;
}
