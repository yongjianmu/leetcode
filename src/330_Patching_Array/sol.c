/*******************************************************************************************************
* nums[i] <= known_sum，更新已知范围为：[1,known_sum + nums[i] )
* nums[i] >  known_sum,  添加known_sum进数组才能达到最大的范围，所以已知范围更新为：[1,known_sum *2  )
* NOTICE: 左边是不封口的，也就是说当know_sum等于最大值时，还是要再乘以二（左移）
********************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int minPatches(int* nums, int numsSize, int n)
{
	int count = 0;
	long range = 1;
	int i = 0;
	int flag = 0;

	while(range <= n)
	{
		if((i < numsSize) && range >= nums[i])
		{
			range += nums[i++];
		}
		else
		{
			range <<= 1;
			++count;
		}
		printf("range: %ld\n", range);
	}
	return count;
}

int main()
{
	int nums[] = {1,2,16,19,31,35,36,64,64,67,69,71,73,74,76,79,80,91,95,96,97};
	printf("Need insert %d numbers\n", minPatches(nums, 21, 8));
	return 0;
}
