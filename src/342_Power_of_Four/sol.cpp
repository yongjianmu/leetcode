#include "../include/header.h"

/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4. 

Example:
 Given num = 16, return true. Given num = 5, return false. 

Follow up: Could you solve it without loops/recursion? 
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(0 == num)
		{
			return false;
		}
		
		int ref = 0x55555555; //  0101 0101 0101 0101 0101 0101 0101 0101
		return (num > 0) && (num == (num & ref)) && ((num & (num - 1)) == 0);
    }
};

int main()
{
	int num = 2;
	Solution sol;
	cout << sol.isPowerOfFour(num) << endl;
	
	return 0;
}
