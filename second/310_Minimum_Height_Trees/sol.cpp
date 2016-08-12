#include "../include/header.h"

/*
For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<int> ret;
        if(0 == n)
        {
            return ret;
        }
        if(0 == edges.size())
        {
            ret.push_back(0);
            return ret;
        }

        while(true)
        {
            vector<int> in_degree (n, 0);
            bool need_strim = false;
            for(auto iter = edges.begin(); iter != edges.end(); ++iter)
            {
                ++in_degree[iter->first];
                ++in_degree[iter->second];
                if(in_degree[iter->first] > 1 || in_degree[iter->second] > 1)
                {
                    need_strim = true;
                }
            }

            if(need_strim)
            {
                for(auto iter = edges.begin(); iter != edges.end(); )
                {
                    if(1 == in_degree[iter->first])
                    {
                        --in_degree[iter->first];
                        edges.erase(iter);
                    }
                    else if(1 == in_degree[iter->second])
                    {
                        --in_degree[iter->second];
                        edges.erase(iter);
                    }
                    else
                    {
                        ++iter;
                    }
                }

                if(edges.size() == 0)
                {
                    for(auto iter = in_degree.begin(); iter != in_degree.end(); ++iter)
                    {
                        if(0 != *iter)
                        {
                            ret.push_back(distance(in_degree.begin(), iter));
                        }
                    }
                    break;
                }
            }
            else
            {
                for(auto iter = in_degree.begin(); iter != in_degree.end(); ++iter)
                {
                    if(0 != *iter)
                    {
                        ret.push_back(distance(in_degree.begin(), iter));
                    }
                }
                break;
            }
        }
        return ret;
    }
};
