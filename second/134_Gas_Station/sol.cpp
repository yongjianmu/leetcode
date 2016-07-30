#include "../include/header.h"


/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len_gas = gas.size(), len_cost = cost.size();
        if(len_gas != len_cost)
        {
            return -1;
        }

        int sum = 0, total = 0, station = -1;
        for(int i = 0; i < len_gas; ++i)
        {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];

            if(0 > sum)
            {
                station = i;
                sum = 0;
            }
        }

        return 0 <= total ? station + 1 : -1;
    }
};
