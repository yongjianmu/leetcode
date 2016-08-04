#include "../include/header.h"


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        int* in_degree = new int[numCourses];
        memset(in_degree, 0, numCourses * sizeof(int));
        int size = prerequisites.size();
        if(0 == size)
        {
            return true;
        }

        for(int i = 0; i < size; ++i)
        {
            ++in_degree[prerequisites[i].second];
        }

        while(true)
        {
            bool decrease_flag = false;
            for(auto iter = prerequisites.begin(); iter != prerequisites.end(); )
            {
                if(iter->first <= numCourses && 0 == in_degree[iter->first])
                {
                    --in_degree[iter->second];
                    prerequisites.erase(iter);
                    decrease_flag = true;
                }
                else
                {
                    ++iter;
                }
            }

            if(!decrease_flag)
            {
                break;
            }
        }

        delete [] in_degree;
        return 0 == prerequisites.size();
    }
};
