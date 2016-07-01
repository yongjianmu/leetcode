#include "../include/header.h"

/*
 * Repeately delete all the nodes which have in_degree = 0
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<vector<int> > g(numCourses);
        vector<int> in_degree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); ++i)
        {
            g[prerequisites[i].second].push_back(prerequisites[i].first);
            ++in_degree[prerequisites[i].first];
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
        {
            if(0 == in_degree[i])
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(auto it = g[cur].begin(); it != g[cur].end(); ++it)
            {
                if(--in_degree[*it] == 0)
                {
                    q.push(*it);
                }
            }
        }

        for(int i = 0; i < numCourses; ++i)
        {
            if(0 != in_degree[i])
            {
                return false;
            }
        }

        return true;
    }
};
