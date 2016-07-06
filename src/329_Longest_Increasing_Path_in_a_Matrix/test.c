#include <stdio.h>

void add(int& n)
{
	n++;
}

int main()
{
	int n = 0;
	add(n);
	printf("n=%d\n", n);
	return 0;
}
