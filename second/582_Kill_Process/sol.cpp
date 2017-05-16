#include "../include/header.h"

class Solution {
public:
    void dfs(unordered_map<int, vector<int> >& dict, int kill, vector<int>& ret)
    {
        ret.push_back(kill);
        auto iter = dict.find(kill);
        if(iter == dict.end() || iter->second.size() == 0) return;
        for(auto it = iter->second.begin(); it != iter->second.end(); ++it)
        {
            dfs(dict, *it, ret);
        }
    }

    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> ret;
        int n = pid.size();
        if(0 == n) return ret;
        
        unordered_map<int, vector<int> > dict;
        for(int i = 0; i < n; ++i)
        {
            if(ppid[i] != 0) dict[ppid[i]].push_back(pid[i]);
        }
        
        dfs(dict, kill, ret);
        return ret;
    }
};

int main()
{
    vector<int> pid = {1,3,10,5};
    vector<int> ppid = {3,0,5,3};
    Solution sol;
    vector<int> result = sol.killProcess(pid, ppid, 5);
    printResult();
    printVector1D(result);

    return 0;
}
