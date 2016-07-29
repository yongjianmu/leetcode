#include "../include/header.h"


/*
   Given a string s, partition s such that every substring of the partition is a palindrome.

   Return all possible palindrome partitioning of s.

   For example, given s = "aab",
   Return

   [
   ["aa","b"],
   ["a","a","b"]
   ]
   */

class Solution {
public:

    int minCut(string s) {
        int n = s.length();
        int *dp = new int[n+1];
        unordered_set<string> dic;
        for (int i = 0; i <= n; i++)	dp[i] = i - 1;
        for (int i = 0; i < n; i++){
            for (int j = 0;i - j >= 0 && i+j <n && s[i - j] == s[i + j]; j++){
                dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
            }
            for (int j = 1; i - j +1 >= 0 && i + j<n && s[i - j +1] == s[i + j]; j++){
                dp[i + j + 1] = min(dp[i + j + 1 ], dp[i - j + 1] + 1);
            }	
        }
        int ans = dp[n];
        delete[] dp;
        return ans;
    }
};

int main()
{
    string input = "aab";
    Solution sol;
    int result = sol.minCut(input);
    printResult();
    cout << result << endl;

    return 0;
}
