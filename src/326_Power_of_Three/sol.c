#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef		char		bool;
#define		TRUE		1
#define		FALSE		0

bool isPowerOfThree(int n)
{
	if(0 == n)
	{
		return FALSE;
	}
	return n == pow(3, (round(log(n)/log(3)))) ? TRUE : FALSE;
}

int main()
{
	printf("%d\n", isPowerOfThree(27));
	printf("%d\n", isPowerOfThree(81));
	printf("%d\n", isPowerOfThree(21));
	printf("%d\n", isPowerOfThree(18));
	printf("%d\n", isPowerOfThree(9));
	return 0;
}
