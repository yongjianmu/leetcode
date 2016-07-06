#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std;

/*
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/


class Solution {
public:
    bool solve(string cur, vector<string>& ret, int len, unordered_map<string, map<string, int> >& mp)
    {
        if(len == ret.size())
        {
            return true;
        }

        for(map<string, int>::iterator iter = mp[cur].begin(); iter != mp[cur].end(); ++iter)
        {
            if(0 != iter->second)
            {
                --iter->second;
                ret.push_back(iter->first);
                if (solve(iter->first, ret, len, mp))
                {
                    return true;
                }
                ret.pop_back();
                ++iter->second;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<pair<string, string> > tickets) {
        unordered_map<string, map<string, int> > mp;
        for(auto& p : tickets)
        {
            ++mp[p.first][p.second];
        }
        string start = "JFK";
        vector<string> ret;
        ret.push_back(start);
        solve(start, ret, tickets.size() + 1, mp);
        return ret;
    }
};

