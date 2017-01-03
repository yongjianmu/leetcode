#include "../include/header.h"

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        if(2 >= n) return 0;
        
        int ret = 0;
        for(int i = 0; i < n; ++i)
        {
            unordered_map<long long, int> ump;
            for(int j = 0; j < n; ++j)
            {
                if(i == j) continue;

                long long dis = static_cast<long long> (pow((points[i].first - points[j].first), 2)) + static_cast<long long> (pow((points[i].second - points[j].second), 2));
                ++ump[dis];
            }
            
            for(auto iter = ump.begin(); iter != ump.end(); ++iter)
            {
                if(iter->second < 2) continue;
                ret += iter->second * (iter->second - 1);
            }
        }
        return ret;
    }
};

int main()
{
    vector<pair<int, int> > points = {
        {0, 0},
        {1, 0},
        {2, 0}
    };

    Solution sol;
    int result = sol.numberOfBoomerangs(points);
    printResult();
    cout << result << endl;

    return 0;
}
