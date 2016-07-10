#include "../include/header.h"

class Solution {
public:
    
	string reverseString(string s) {
        int left = 0;
		int right = s.length() - 1;
		while(left < right)
		{
			char tmp = s[left];
			s[left] = s[right];
			s[right] = tmp;
			++left;
			--right;
		}
		return s;
    }
};

int main()
{
	string input = "hello \n i'll";
	Solution sol;
	string result = sol.reverseString(input);
	cout << "#### Result ####" << endl;
	cout << result << endl;
	
	return 0;
}