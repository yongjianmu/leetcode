#include "../include/header.h"

int sol(vector<int> grade, vector<int> wait)
{
    int size = grade.size();
    if(0 == size)
    {
        return 0;
    }

    vector<int> dp(size, 0);
    int cur_max = INT_MIN;
    for(int i = size - 1; i >= 0; --i)
    {
        if(i + wait[i] >= size)
        {
            dp[i] = max(grade[i], cur_max);
        }
        else
        {
            dp[i] += grade[i] + dp[i + wait[i]];
        }
        cur_max = max(cur_max, dp[i]);
    }

    return dp[0];
}

int main()
{
    vector<int> grade = {5,3,2,1,3};
    //vector<int> wait = {6,1,4,3,1};
    //vector<int> wait = {6,1,2,3,1};
    vector<int> wait = {1,1,1,1,1};
    int result = sol(grade, wait);
    printResult();
    cout << result << endl;

    return 0;
}
