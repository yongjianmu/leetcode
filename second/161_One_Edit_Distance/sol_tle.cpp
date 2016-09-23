class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len_s = s.length(), len_t = t.length();
        if(1 < abs(len_s - len_t))
        {
            return false;
        }
        
        vector<vector<int> > dp(len_s + 1, vector<int>(len_t + 1, 0));
        for(int i = 1; i <= len_s; ++i)
        {
            dp[i][0] = i;
        }
        for(int j = 1; j <= len_t; ++j)
        {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= len_s; ++i)
        {
            for(int j = 1; j <= len_t; ++j)
            {
                if(s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
                //cout << dp[i][j] << endl;
            }
        }
        
        return dp[len_s][len_t] == 1;
    }
};
