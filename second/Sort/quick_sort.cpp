#include "../include/header.h"

void quick_sort(vector<int>& s, int l, int r)
{
    if(l >= r) return;

    int i = l, j = r, x = s[l];
    while(i < j)
    {
        while((i < j) && (s[j] >= x)) --j;
        if(i < j) s[i++] = s[j];

        while((i < j) && (s[i] <= x)) ++i;
        if(i < j) s[j--] = s[i];
    }
    s[i] = x;
    quick_sort(s, l, i - 1);
    quick_sort(s, i + 1, r);
}

int main()
{
    vector<int> input = {2,3,4,5,1,9,6,0};
    quick_sort(input, 0, input.size() - 1);
    printResult();
    printVector1D(input);
    return 0;
}
