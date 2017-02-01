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
        for(int i = s; i <= e; ++i)
        {
            if(curLevel == maxLevel)
            {
                A[curLevel][i] = 1;
            }
            else
            {
                A[curLevel][i] = ((A[curLevel + 1][2 * i]) && A[curLevel + 1][2 * i + 1]) ? 1 : 0;
            }
        }
        --curLevel;
        s >>= 1; e >>= 1;
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
