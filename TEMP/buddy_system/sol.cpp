#include "../../second/include/header.h"

vector<vector<int> > A = {
    {0},
    {1,0},
    {1,1,0,0},
    {1,1,1,1,0,0,0,0}
};

void set_bits(int start, int len)
{
    int maxLevel = A.size() - 1;
    if(-1 == maxLevel) return;
    if(len < 1 || start > A[maxLevel].size() - 1) return;

    int s = start, e = min(static_cast<int> (A[maxLevel].size() - 1), start + len - 1);
    int curLevel = maxLevel;
    while(curLevel >= 0)
    {
        cout << s << ", " << e << endl;
        for(int i = s; i <= e; ++i)
        {
            A[curLevel][i] = 1;
        }
        int s_buddy = s + (s % 2 == 1 ? -1 : 1);
        int e_buddy = e + (e % 2 == 1 ? -1 : 1);
        int s_bit = A[curLevel][s] && A[curLevel][s_buddy];
        int e_bit = A[curLevel][e] && A[curLevel][e_buddy];
        --curLevel;
        s >>= 1; e >>= 1;
        if(0 == s_bit) ++s;
        if(0 == e_bit) --e;
    }
}

void clear_bits(int start, int len)
{
    int maxLevel = A.size() - 1;
    if(-1 == maxLevel) return;
    if(len < 1 || start > A[maxLevel].size() - 1) return;

    int s = start, e = min(static_cast<int> (A[maxLevel].size() - 1), start + len - 1);
    int curLevel = maxLevel;
    while(curLevel >= 0)
    {
        for(int i = s; i <= e; ++i)
        {
            A[curLevel][i] = 0;
        }
        --curLevel;
        s >>= 1; e >>= 1;
    }
}

int main()
{
    set_bits(3, 3);
    printVector2D(A);
    clear_bits(0, 1);
    printVector2D(A);
    return 0;
}
