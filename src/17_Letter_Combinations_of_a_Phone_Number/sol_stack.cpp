#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret;
        string comb(digits.size(), '\0');
        string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        stack<int> s;

        for(int i = 0; i < digits.size(); ++i)
        {
            s.push(digits[i] - '0');
        }

        while(!s.empty())
        {

        }

        return ret;
    }
};

int main()
{
    string digits("234");
    Solution sol;
    vector<string> result = sol.letterCombinations(digits);
    vector<string>::iterator iter;
    for(iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << *iter << endl;
    }

    return 0;
}
