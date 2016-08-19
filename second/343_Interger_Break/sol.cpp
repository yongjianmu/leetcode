#include "../include/header.h"

/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get. 

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4). 
*/

class Solution {
public:
    int integerBreak(int n) {
        if(2 == n)
		{
			return 1;
		}
		else if(3 == n)
		{
			return 2;
		}
		
		int count_3 = n / 3;
		int count_2 = 0;
		int reminder = n % 3;
		if(2 == reminder)
		{
			count_2 = 1;
		}
		else if(1 == reminder)
		{
			count_2 = 2;
			--count_3;
		}
		
		return pow(2, count_2) * pow(3, count_3);
    }
};

int main()
{
	int n = 10;
	Solution sol;
	int result = sol.integerBreak(n);
	cout << "#### Result ####" << endl;
	cout << result << endl;
	
	return 0;
}
