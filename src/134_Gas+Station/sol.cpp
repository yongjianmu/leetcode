#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len_gas = gas.size();
        int len_cost = cost.size();
        if(len_gas != len_cost)
        {
            return -1;
        }

        int total = 0;
        int sum = 0;
        int j = -1;
        for(int i = 0; i < len_gas; ++i)
        {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];

            if(0 > sum)
            {
                j = i;
                sum = 0;
            }
        }

        return total >= 0 ? j + 1 : -1;
    }
};

int main()
{
    vector<int> gas;
    gas.push_back(5);
    gas.push_back(6);
    gas.push_back(7);
    vector<int> cost;
    cost.push_back(6);
    cost.push_back(1);
    cost.push_back(8);

    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
