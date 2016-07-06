/********
 * 题意：给一个数组nums，给出最大值upper，最小值lower，求有多少个区间 [i,j](i⩽j) 满足 lower⩽ ∑_{k=i}^j nums[k]⩽upper
 * ****/

int countRangeSum(int* nums, int numsSize, int lower, int upper)
{
    int ret = 0;
    int i = 0;
    int j = 0;

    if(0 == numsSize)
    {
        return ret;
    }

    long* sum = (long*)malloc(sizeof(long) * (numsSize + 1));
    sum[0] = 0;

    for(i=0; i<numsSize; ++i)
    {
        sum[i + 1] = sum[i] + nums[i];
    }

    /* Use double pointer */
    i = 0;
    while(1)
    {

    }

    //ToDo: free sum
}
