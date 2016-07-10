#include "../include/header.h"

/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
 Given s = "hello", return "holle". 

Example 2:
 Given s = "leetcode", return "leotcede". 

*/

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
		int right = s.length() - 1;
		string ref = "aeiouAEIOU";
		
		bool left_find = false;
		bool right_find = false;
		while(left < right)
		{
			for(int i = 0; i < ref.length(); ++i)
			{
				if(!left_find)
				{
					if(s[left] == ref[i])
					{
						left_find = true;
					}
				}
				
				if(!right_find)
				{
					if(s[right] == ref[i])
					{
						right_find = true;
					}
				}
				
			}

			if(left_find && right_find)
			{
				char tmp = s[left];
				s[left] = s[right];
				s[right] = tmp;
				++left;
				--right;
				left_find = false;
				right_find = false;
			}
			else if(left_find && !right_find)
			{
				--right;
			}
			else if(!left_find && right_find)
			{
				++left;
			}
			else
			{
				++left;
				--right;
			}
		}
		return s;
    }
};

int main()
{
	string s = "aA";
	Solution sol;
	string result = sol.reverseVowels(s);
	cout << "#### Result ####" << endl;
	cout << result << endl;
	
	return 0;
}