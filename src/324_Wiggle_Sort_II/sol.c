#include <stdlib.h>
#include <stdio.h>

int cmp(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

void wiggleSort(int* nums, int numsSize) 
{
	int mid = (numsSize + 1) >> 1;
	int end = numsSize;
	int* temp = (int*)malloc(sizeof(int) * numsSize);
	int i = 0;

	qsort(nums, numsSize, sizeof(nums[0]), cmp);
	
	for(i=0; i<numsSize; ++i)
	{
		temp[i] = 0 == (i & 1)? nums[--mid] : nums[--end];
	}

	for(i=0; i<numsSize; ++i)
	{
		nums[i] = temp[i];
	}
	
	if(NULL != temp)
	{
		free(temp);
	}
}

int main()
{
	int i = 0;
	int input[] = {1,2,3,4,5,6};
	
	wiggleSort(input, 6);
	for(i=0; i<sizeof(input)/sizeof(input[0]); ++i)
	{
		printf("%d\n", input[i]);
	}

	return 0;
}
