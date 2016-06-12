#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
    	if(2 >= n)
		{
			return n;
		}

		// return climbStairs(n - 1) + climbStairs(n - 2); // TLE

		/*
		int zero = 0, one  = 1, two = 1;
		for(int i = 1; i <= n; ++i)
		{
			two = zero + one;
			zero = one;
			one = two;
		}
		return two;
		*/

		
		int curr = 0, one = 1, two = 2;
		for(int i = 3; i <= n; ++i)
		{
			curr = one + two;
			one = two;
			two = curr;
		}
		return curr;
		
    }
};

int main()
{
	Solution sol;
	cout << sol.climbStairs(5) << endl;
	return 0;
}
