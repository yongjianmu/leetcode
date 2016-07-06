#include <string>
#include <iostream>

using namespace std;


/*
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if(1 >= len)
        {
            return true;
        }

        int start = 0;
        int end = len - 1;
        while(start <= end)
        {
            if('A' <= s[start] && 'Z' >= s[start])
            {
                s[start] += 32;
            }

            if('A' <= s[end] && 'Z' >= s[end])
            {
                s[end] += 32;
            }

            if(('a' > s[start] || 'z' < s[start]) && ('0' > s[start] || '9' < s[start]))
            {
                ++start;
                continue;
            }

            if(('a' > s[end] || 'z' < s[end]) && ('0' > s[end] || '9' < s[end]))
            {
                --end;
                continue;
            }

            if(s[start] != s[end])
            {
                return false;
            }
            ++start;
            --end;
        }

        return true;
    }
};

int main()
{
    //string input = "A man, a plan, a canal: Panama";
    string input = "1b1";
    Solution sol;
    cout << sol.isPalindrome(input) << endl;
    return 0;
}
