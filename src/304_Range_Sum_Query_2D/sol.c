#include <stdio.h>
#include <stdlib.h>

struct NumMatrix 
{
	int** Matrix;
	int RowSize;
	int ColSize;
};

/** Initialize your data structure here. */
struct NumMatrix* NumMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize)
{
	struct NumMatrix* st_matrix = (struct NumMatrix*)malloc(sizeof(struct NumMatrix));
	st_matrix->Matrix = matrix;
	st_matrix->RowSize = matrixRowSize;
	st_matrix->ColSize = matrixColSize;
	return st_matrix;
}

int sumRegion(struct NumMatrix* numMatrix, int row1, int col1, int row2, int col2)
{
	int ret = 0;
	int i = 0, j = 0;

	for(i = row1; i <= row2; ++i)
	{
		for(j = col1; j <= col2; ++j)
		{
			if(row2 < numMatrix->RowSize && col2 < numMatrix->ColSize)
			{
				ret += numMatrix->Matrix[i][j];
			}
		}
	}
	return ret;
}

/** Deallocates memory previously allocated for the data structure. */
void NumMatrixFree(struct NumMatrix* numMatrix)
{
	if(NULL != numMatrix)
	{
		free(numMatrix);
	}
}

// Your NumMatrix object will be instantiated and called as such:
// struct NumMatrix* numMatrix = NumMatrixCreate(matrix, matrixRowSize, matrixColSize);
// sumRegion(numMatrix, 0, 1, 2, 3);
// sumRegion(numMatrix, 1, 2, 3, 4);
// NumMatrixFree(numMatrix);


int main()
{
	int i = 0, j = 0;
	int* matrix[5];
	for(i = 0; i < 5; ++i)
	{
		matrix[i] = (int*)malloc(sizeof(int) * 5);
	}

	int tempMatrix[5][5] = 
	{
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5}
	};

	for(i = 0; i < 5; ++i)
	{
		for(j = 0; j < 5; ++j)
		{
			matrix[i][j] = tempMatrix[i][j]; 
		}
	}

	struct NumMatrix* numMatrix = NumMatrixCreate(matrix, 5, 5);
	printf("sub1: %d\n", sumRegion(numMatrix, 2, 1, 4, 3));
	printf("sub2: %d\n", sumRegion(numMatrix, 1, 1, 2, 2));
	NumMatrixFree(numMatrix);

	return 0;
}
