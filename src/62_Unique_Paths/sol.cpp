#include <iostream>

using namespace std;

class Solution {
public:
    void getPaths(int m, int n, int& ret)
    {
        if(1 == m && 1 == n)
        {
            ++ret;
            return;
        }

        if(m > 1)
        {
            getPaths(m - 1, n, ret);
        }

        if(n > 1)
        {
            getPaths(m, n - 1, ret);
        }
    }

    int uniquePaths(int m, int n) {
        if(0 == m || 0 == n)
        {
            return 0;
        }
        int ret = 0;
        getPaths(m, n, ret);
        return ret;
    }
};

int main()
{
    int m = 2, n = 2;
    Solution sol;
    cout << sol.uniquePaths(m, n) << endl;
    return 0;
}
