#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret = -1;
        int len_gas = gas.size();
        int len_cost = cost.size();
        if(len_gas != len_cost)
        {
            return ret;
        }

        bool flag = false;
        for(int k = 0; k < len_gas; ++k)
        {
            if(flag)
            {
                break;
            }
            int remain = 0;
            int curr = k;
            for(int i = 0; i < len_gas; ++i)
            {
                remain += gas[curr] - cost[curr];
                if(remain < 0)
                {
                    break;
                }
                else
                {
                    if(i == len_gas - 1)
                    {
                        ret = k;
                        flag = true;
                        break;
                    }
                }

                if(len_gas - 1 == curr)
                {
                    curr = 0;
                }
                else
                {
                    ++curr;
                }
            }
        }
        return ret;
    }
};

int main()
{
    vector<int> gas;
    gas.push_back(4);
    vector<int> cost;
    cost.push_back(5);

    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
