#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret(n, vector<int>(n, 0));
        if(0 == n)
        {
            return ret;
        }

        int total = n * n + 1, cnt = 1, row = (n >> 1) + 1;

        for(int k = 0; k < row; ++k)
        {
            for(int i = k; i < n - k && cnt < total; ++i, ++cnt)
            {
                ret[k][i] = cnt;
            }

            for(int i = k + 1; i < n - k && cnt < total; ++i, ++cnt)
            {
                ret[i][n - k - 1] = cnt;
            }

            for(int i = n - k - 2; i >= k && cnt < total; --i, ++cnt)
            {
                ret[n - k - 1][i] = cnt;
            }

            for(int i = n - k - 2; i > k && cnt < total; --i, ++cnt)
            {
                ret[i][k] = cnt;
            }
        }
        return ret;
    }
};
