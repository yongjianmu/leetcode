#include "../include/header.h"

/*
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
*/

class Solution {
public:
	string shortestPalindrome(string s)
    {
        int n = s.size();
        if(n == 0) return s;
        
        int i = n;
        string v = s; 
        reverse(v.begin(), v.end());  //Reverse s.
        
        for(; i >= 1; --i)
        {
            if(s.substr(0, i) == v.substr(n - i)) break;    //palindrome?
        }

        return v.substr(0, n - i) + s;
    }
};

int main()
{
    string input = "abcd";
    Solution sol;
    string result = sol.shortestPalindrome(input);
    cout << "#### Result ####" << endl;
    cout << result << endl;

    return 0;
}
