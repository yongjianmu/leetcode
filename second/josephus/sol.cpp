#include "../include/header.h"

int survivor(int n, int k)
{
    int ret = 0;
    for(int i = 2; i <= n; ++i)
    {
        ret = (ret + k) % i;
    }
    return ret;
}

void addOne(int& pos, vector<int> vec, int n)
{
    if(pos == n - 1) pos = 0;
    else ++pos;
}

int bf(int n, int k)
{
    vector<int> vec(n, 1);
    int cnt = n;

    int pos = 0;
    while(cnt > 1)
    {
        for(int i = 0; i < k; ++i)
        {
            if(i == k - 1)
            {
                vec[pos] = 0;
                --cnt;
            }

            addOne(pos, vec, n);
            while(vec[pos] == 0) addOne(pos, vec, n);
        }
    }
    
    int ret = 0;
    while(ret < n)
    {
        if(vec[ret] == 1) break;
        ++ret;
    }
    return ret;
}

int bf_vec(int n, int k)
{
    vector<int> vec(n);
    for(int i = 0; i < n; ++i)
    {
        vec[i] = i + 1;
    }

    int cnt = n;
    auto iter = vec.begin();
    while(cnt > 1)
    {
        for(int i = 0; i < k; ++i)
        {
            if(i == k - 1)
            {
                cout << *iter << endl;
                vec.erase(iter);
                --cnt;
            }
            else
            {
                ++iter;
            }
            if(iter >= vec.end()) iter = vec.begin();
        }
    }
    return vec[0];
}

int main()
{
    int n = 5, k = 4;
    int result = survivor(n, k);
    printResult();
    cout << result << endl;

    result = bf(n, k);
    printResult();
    cout << result << endl;

    result = bf_vec(n, k);
    printResult();
    cout << result << endl;
    return 0;
}
