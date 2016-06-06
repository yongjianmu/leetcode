#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void recursiveGetLongest(int** matrix, int row_size, int col_size,
                        int current_row, int current_col, int current_dir,
                        int current_num, int* max_num)
{
    int num = current_num;
    if(current_col < col_size - 1)
    {
        if((matrix[current_row][current_col] < matrix[current_row][current_col + 1]) && (3 != current_dir))
        {
            /* Move to right */
            ++num;
            if(num > *max_num)
            {
                *max_num = num;
            }
            recursiveGetLongest(matrix, row_size, col_size,
                                current_row, current_col + 1, 4, num, max_num);
            --num;
        }
    }

    if(0 < current_col)
    {
        if((matrix[current_row][current_col] < matrix[current_row][current_col - 1]) && (4 != current_dir))
        {
            /* Move to left */
            ++num;
            if(num > *max_num)
            {
                *max_num = num;
            }
            recursiveGetLongest(matrix, row_size, col_size,
                                current_row, current_col - 1, 3, num, max_num);
            --num;
        }
    }

    if(current_row < row_size - 1)
    {
        if((matrix[current_row][current_col] < matrix[current_row + 1][current_col]) && (1 != current_dir))
        {
            /* Move to down */
            ++num;
            if(num > *max_num)
            {
                *max_num = num;
            }
            recursiveGetLongest(matrix, row_size, col_size,
                                current_row + 1, current_col, 2, num, max_num);
            --num;
        }
    }

    if(0 < current_row)
    {
        if((matrix[current_row][current_col] < matrix[current_row - 1][current_col]) && (2 != current_dir))
        {
            /* Move to Up */
            ++num;
            if(num > *max_num)
            {
                *max_num = num;
            }
            recursiveGetLongest(matrix, row_size, col_size,
                                current_row - 1, current_col, 1, num, max_num);
            --num;
        }
    }
}

int longestIncreasingPath(int** matrix, int matrixRowSize, int matrixColSize)
{
    /* Define the direction
    * 0: None
    * 1: Up
    * 2: Down
    * 3: Left
    * 4: Right
    */
    int max_num = 0;
    int i = 0;
    int j = 0;

    for(i=0; i<matrixColSize; ++i)
    {
        for(j=0; j<matrixRowSize; ++j)
        {
            recursiveGetLongest(matrix, matrixRowSize, matrixColSize,
                                j, i, 0, 1, &max_num);
        }
    }


    return max_num;
}

int main()
{
    int* nums[3];
	int i = 0;
	int j = 0;

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
