#include "../../include/header.h"

class cmp
{
public:
    bool operator()(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) const
    {
        return a.first < b.first;
    }
};

class Solution
{
public:
    vector<int> sortMatrix(vector<vector<int> > matrix)
    {
        vector<int> ret;
        int row = matrix.size();
        if(0 == row)
        {
            return ret;
        }
        int col = matrix[0].size();
        if(0 == col)
        {
            return ret;
        }

        set<pair<int, pair<int, int> >, cmp> st;
        st.insert(make_pair(matrix[0][0], make_pair(0, 0)));

        while(0 != st.size())
        {
            auto iter = st.begin();
            pair<int, pair<int, int> > cur = *iter;
            ret.push_back(cur.first);
            int x = cur.second.first;
            int y = cur.second.second;
            if(x < row - 1)
            {
                st.insert(make_pair(matrix[x + 1][y], make_pair(x + 1, y)));
            }
            if(y < col - 1)
            {
                st.insert(make_pair(matrix[x][y + 1], make_pair(x, y + 1)));
            }

            st.erase(iter);
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > input = {
        {1,3,5},
        {2,5,9},
        {8,10,12}
    };

    vector<int> result = sol.sortMatrix(input);
    printResult();
    printVector1D(result);

    return 0;
}
