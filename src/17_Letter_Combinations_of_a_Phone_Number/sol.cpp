#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ret;
        if(0 == digits.length())
        {
            return ret;
        }
        string comb(digits.size(), '\0');
        string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        findComb(digits, dict, 0, comb, ret);

        return ret;
    }

    void findComb(string digits, string dict[], int index, string comb, vector<string>& ret)
    {
        if(index == digits.size())
        {
            ret.push_back(comb);
            return;
        }

        string letter = dict[digits[index] - '0'];

        for(int i = 0; i < letter.size(); ++i)
        {
            comb[index] = letter[i];
            findComb(digits, dict, index + 1, comb, ret);
        }
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
