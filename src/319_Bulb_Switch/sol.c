#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int bulbSwitch(int n) 
{
	return sqrt(n);
}


int main()
{
	int n = 24;
	printf("Still %d bulbs on.\n", bulbSwitch(n));
	return 0;
}