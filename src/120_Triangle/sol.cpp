#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

/*
[
    [2],
    [3,4],
    [6,5,7],
    [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

class Solution {
public:
    int mSum;
    vector<int> mLast;

    void solve(vector<vector<int> >& triangle, int level, int curr_level)
    {
        vector<int> tmp;
        tmp.insert(tmp.begin(), mLast.begin(), mLast.end());
        for(int i = 0; i <= curr_level; ++i)
        {
            if(curr_level == level - 1)
            {
                if(0 == i)
                {
                    mSum = mLast[i] + triangle[curr_level][i];
                }
                else if(curr_level == i)
                {
                    mSum = min(mSum, mLast[i - 1] + triangle[curr_level][i]);
                }
                else
                {
                    mSum = min(mSum,  min(mLast[i - 1], mLast[i]) + triangle[curr_level][i]);
                }
            }
            else
            {
                if(0 == i)
                {
                    mLast[i] = tmp[i] + triangle[curr_level][i];
                }
                else if(curr_level == i)
                {
                    mLast.push_back(tmp[i - 1] + triangle[curr_level][i]);
                }
                else
                {
                    mLast[i] = min(tmp[i - 1], tmp[i]) + triangle[curr_level][i];
                }
            }
        }

        if(curr_level < level - 1)
        {
            solve(triangle, level, curr_level + 1);
        }
    }

    int minimumTotal(vector<vector<int> >& triangle) {
        mSum = 0;
        int level = triangle.size();
        if(0 == level)
        {
            return mSum;
        }
        else if(1 == level)
        {
            return triangle[0][0];
        }

        mLast.push_back(triangle[0][0]);
        solve(triangle, level, 1);
        return mSum;
    }
};

int main()
{
    vector<vector<int> > input;
    vector<int> r1;
    vector<int> r2;
    vector<int> r3;
    vector<int> r4;
    r1.push_back(2);
    r2.push_back(3);
    r2.push_back(4);
    r3.push_back(6);
    r3.push_back(5);
    r3.push_back(7);
    r4.push_back(4);
    r4.push_back(1);
    r4.push_back(8);
    r4.push_back(3);
    input.push_back(r1);
    input.push_back(r2);
    input.push_back(r3);
    input.push_back(r4);

    Solution sol;
    cout << sol.minimumTotal(input) << endl;

    return 0;
}
