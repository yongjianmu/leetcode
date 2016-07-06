/****
* Use DFS + Memorization
****/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int recursiveGetLongest(int** matrix, int row_size, int col_size,
                        int current_row, int current_col, int** mem)
{
    int dir_row[4] = {1, -1, 0, 0};
    int dir_col[4] = {0, 0, 1, -1};
    int step_row = 0;
    int step_col = 0;
    int i = 0;
    int value = 0;

    if(0 != mem[current_row][current_col])
    {
        return mem[current_row][current_col];
    }

    for(i=0; i<4; ++i)
    {
        step_row = current_row + dir_row[i];
        step_col = current_col + dir_col[i];

        if((step_row >= 0)              \
            && (step_col >= 0)          \
            && (step_row < row_size)   \
            && (step_col < col_size)   \
            )
        {
            if(matrix[step_row][step_col] > matrix[current_row][current_col])
            {
                value = recursiveGetLongest(matrix, row_size, col_size, step_row, step_col, mem);
                if(mem[current_row][current_col] < value)
                {
                    mem[current_row][current_col] = value;
                }
            }
        }
    }
    return ++mem[current_row][current_col];
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize)
{
    int ret = 0;
    int value = 0;
    int* mem[matrixRowSize];
    int i = 0;
    int j = 0;

    for(i=0; i<matrixRowSize; ++i)
    {
        mem[i] = (int*)malloc(sizeof(int) * matrixColSize);
        for(j=0; j<matrixColSize; ++j)
        {
            mem[i][j] = 0;
        }
    }

    for(i=0; i<matrixRowSize; ++i)
    {
        for(j=0; j<matrixColSize; ++j)
        {
            value = recursiveGetLongest(matrix, matrixRowSize, matrixColSize, i, j, mem);
            if(ret < value)
            {
                ret = value;
            }
        }
    }

    return ret;

}

int main()
{
    int* nums[3];
	int i = 0;

	for(i=0; i<3; ++i)
	{
		nums[i] = (int*)malloc(sizeof(int)*3);
	}

	nums[0][0] = 9;
	nums[0][1] = 9;
	nums[0][2] = 4;
	nums[1][0] = 6;
	nums[1][1] = 6;
	nums[1][2] = 8;
	nums[2][0] = 2;
	nums[2][1] = 1;
	nums[2][2] = 1;

    printf("path_num: %d\n", longestIncreasingPath(nums, 3, 3));

    return 0;
}
