#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool check(int curr, vector<int>& place)
    {
        for(int j = 0; j < curr; ++j)
        {
            if(place[curr] == place[j] || abs((place[curr] - place[j])) == abs(curr - j))
            {
                return false;
            }
        }
        return true;
    }

    void solve(int curr, int n, vector<int>& place, int& ans)
    {
        if(curr == n)
        {
            ++ans;
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            place[curr] = i;
            if(check(curr, place))
            {
                solve(curr + 1, n, place, ans);
            }
        }
    }

    int totalNQueens(int n) {
        int total = 0;
        vector<int> place(n, 0);
        solve(0, n, place, total);
        return total;
    }
};

int main()
{
    int queue_num = 8;
    Solution sol;
    cout << sol.totalNQueens(queue_num) << endl;
    return 0;
}
