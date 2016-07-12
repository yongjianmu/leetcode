#include "../include/header.h"

/*
Example:

Given matrix = [
[1,  0, 1],
[0, -2, 3]
]
k = 2



The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int> >& matrix, int k) {
        if (matrix.empty()) return 0;
        int ans = INT_MIN, m = matrix.size(), n = matrix[0].size();
        bool row_first = true;
        if (m > n) 
        {
            swap(m, n);
            row_first = false;
        } // keep m < n

        for (int ri = 0; ri < m; ++ri)
        {
            vector<int> temp(n, 0); // sum of each n
            for (int i = ri; i >= 0; --i)
            {
                set<int> sums;
                int sum = 0;
                sums.insert(sum);
                for (int j = 0; j < n; ++j)
                {
                    temp[j] += row_first ? matrix[i][j] : matrix[j][i];
                    sum += temp[j];
                    auto iter = sums.lower_bound(sum - k);
                    if (iter != sums.end())
                    {
                        ans = max(ans, sum - *iter);
                    }
                    sums.insert(sum);
                }
            }
        }
        return ans;
    }
};