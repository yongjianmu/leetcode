#include "../include/header.h"

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int size = words.size();
        if(0 == size)
        {
            return true;
        }
        
        if(size != words[0].length())
        {
            return false;
        }
        
        for(int i = 0; i < size; ++i)
        {
            int len = words[i].length();
            for(int j = i + 1; j < len; ++j)
            {
                if(size < j + 1 || words[j].length() < i + 1 || words[i][j] != words[j][i])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
};

int main()
{
    vector<string> input = {"abc","bde","cefg"};
    Solution sol;
    bool result = sol.validWordSquare(input);
    printResult();
    cout << result << endl;

    return 0;
}
