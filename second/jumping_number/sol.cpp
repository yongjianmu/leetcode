#include "../include/header.h"

void dfs(int cur, int n, vector<int>& ret, unordered_set<int>& dict)
{
    if(cur > n || dict.find(cur) != dict.end()) return;
    ret.push_back(cur);
    dict.insert(cur);
    int x = cur % 10;
    if((x - 1) >= 0) dfs(cur * 10 + x - 1, n, ret, dict);
    if((x + 1) <= 9) dfs(cur * 10 + x + 1, n, ret, dict);
}

vector<int> jumpingNumbers(int n)
{
    vector<int> ret;
    unordered_set<int> dict;
    for(int i = 0; i < 9; ++i)
    {
        dfs(i, n, ret, dict);
    }
    return ret;
}

int main()
{
    int n = 20;
    vector<int> result = jumpingNumbers(n);
    printResult();
    printVector1D(result);
    return 0;
}
