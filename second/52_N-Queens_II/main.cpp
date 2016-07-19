#include "../include/header.h"

class Solution {
public:
    inline bool check(int *place, int cur)
    {
        for (int j = 0; j < cur; j++)
            if (place[cur] == place[j] || abs(place[cur] - place[j]) == cur - j)
                return false;
        return true;
    }

    void solve(int cur, int n, int *place,int &cnt)
    {
        if (cur == n){
            cnt++;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            place[cur] = i;
            if (check(place, cur))
                solve(cur + 1,n,place,cnt);
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        int *place = new int[n];
        solve(0, n, place,ans);
        delete[] place;
        return ans;
    }
};

int main() {
    int n = 4;
    Solution sol;
    int result = sol.totalNQueens(n);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}