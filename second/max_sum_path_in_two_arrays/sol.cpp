#include "../include/header.h"

/*
Max sum path in two arrays
array      Amazon
Given two arrays, the task is to complete the function max_path_sum that takes 4 argument The first two arguments represent the 2 arrays A[], B[] and the last two arguments l1, l2 denote the size of array A and B respectively. The function returns the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays .

Note: You can switch from one array to another array only at common elements.

eg
A [ ] = {2,3,7,10,12}
B [ ] = {1 5 7 8}

Here We start from first element of B which is 1, then we move to 5, then 7. From 7, we switch to A (7 is common) and traverse 10 and 12.

Thus The result will be 1+5+7+10+12 =35
*/

int max_path_sum(vector<int> A, vector<int> B)
{
    //Your code here
    int l1 = A.size(), l2 = B.size();
    int startA = 0, startB = 0, endA = 0, endB = 0;
    int ret0 = 0, ret1 = 0, cnt = 0;
    while(endA < l1 && endB < l2)
    {
        if(A[endA] == B[endB])
        {
            int curA = 0;
            while(startA <= endA) curA += A[startA++];
            
            int curB = 0;
            while(startB <= endB) curB += B[startB++];
            ++endA; ++endB;
            
            if(0 == cnt % 2)
            {
                ret0 += curA;
                ret1 += curB;
            }
            else
            {
                ret0 += curB;
                ret1 += curA;
            }
            ++cnt;
        }
        else if(A[endA] < B[endB]) ++endA;
        else ++endB;
    }
    
    int curA = 0, curB = 0;
    if(endA < l1 - 1)
    {
        while(startA < l1) curA += A[startA++];
    }
    else
    {
        while(startA <= endA) curA += A[startA++];
    }
    
    if(endB < l2 - 1)
    {
        while(startB < l2) curB += B[startB++];
    }
    else
    {
        while(startB <= endB) curB += B[startB++];
    }
    if(0 == cnt % 2)
    {
        ret0 += curA;
        ret1 += curB;
    }
    else
    {
        ret0 += curB;
        ret1 += curA;
    }

    
    return max(ret0, ret1);
}

int main()
{
    vector<int> A = {2,3,7,10,12};
    vector<int> B = {1,5,7,8};
    int result = max_path_sum(A, B);
    printResult();
    cout << result << endl;

    return 0;
}
