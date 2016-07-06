#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>

#define INF 0x7FFFFFFE

int coinChange(int* coins, int coinsSize, int amount) 
{
	int* dp = (int*)malloc(sizeof(int) * (amount + 1));
	int i = 0;
	int j = 0;

	for(i=1; i<=amount; ++i)
	{
		dp[i] = INF;
	}
	dp[0] = 0;
	
	for(i=0; i<=amount; ++i)
	{
		for(j=0; j<coinsSize; ++j)
		{
			if((i + coins[j] <= amount) && (dp[i + coins[j]] > dp[i] + 1))
			{
				dp[i + coins[j]] = dp[i] + 1;
			}
		}
	}

	return dp[amount] == INF? -1 : dp[amount];
}

int main()
{
	int cash[] = {1, 2, 5};
	int size = 3;
	int total = 23;

	printf("Fewest time: %d\n", coinChange(cash, size, total));
	return 0;
}