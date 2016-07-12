#include "../include/header.h"

/*
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first != p2.first ? p1.first < p2.first : p1.second > p2.second;
}

class Solution {
public:
	
    int maxEnvelopes(vector<pair<int, int> >& envelopes) {
        int ret = 0;
        int size = envelopes.size();
        if(0 == size)
        {
            return ret;
        }

        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> dp(size , 1), g(size + 1, INT_MAX);
        for(int i = 0; i < size; ++i)
        {
            int k = lower_bound(++g.begin(), g.end(), envelopes[i].second) - g.begin();
            cout << i << ", " << k << endl;
            dp[i] = k;
            g[k] = envelopes[i].second;
        }

        for(int i = 0; i < size; ++i)
        {
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};

int main()
{
    //vector<pair<int, int> > env = {{5,4},{6,4},{6,7},{2,3}};
    //vector<pair<int, int> > env = {{30,50},{12,2},{3,4},{12,15}};
    vector<pair<int, int> > env = {{46,89},{50,53},{52,68},{72,45},{77, 81}};
    Solution sol;
    int result = sol.maxEnvelopes(env);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
