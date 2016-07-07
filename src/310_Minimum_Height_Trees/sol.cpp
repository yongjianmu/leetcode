#include "../include/header.h"

/*
!Example 1: 

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]] 
        0
        |
        1
       / \
      2   3


return  [1] 

Example 2: 

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]] 
     0  1  2
      \ | /
        3
        |
        4
        |
        5


return  [3, 4]
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<int> ret;
        vector<int> side(n, 0);
        set<int> node;
        for(int i = 0; i < n; ++i)
        {
            node.insert(i);
        }

        while(true)
        {
            vector<int> cur;
            // Scan all edges
            for(auto iter = edges.begin(); iter != edges.end(); ++iter)
            {
                ++side[iter->first];
                ++side[iter->second];
            }

            // Remove leaf node
            for(int i = 0; i < n; ++i)
            {
                if(1 == side[i])
                {
                    side[i] = 0;
                    cur.push_back(i);
                    node.erase(i);
                }
            }

            // Remove edges ToDo: use vector<vector<int> > to store the edges, do not need to traverse
            for(auto iter = edges.begin(); iter != edges.end(); )
            {
                if(find(cur.begin(), cur.end(), iter->first) != cur.end() || find(cur.begin(), cur.end(), iter->second) != cur.end())
                {
                    edges.erase(iter);
                }
                else
                {
                    ++iter;
                }
            }

            if(0 == edges.size())
            {
                if(0 == node.size())
                {
                    return cur;
                }
                else
                {
                    for(auto it = node.begin(); it != node.end(); ++it)
                    {
                        ret.push_back(*it);
                    }
                    return ret;
                }
            }
        }
        
        return ret;
    }
};

int main()
{
    return 0;
}

