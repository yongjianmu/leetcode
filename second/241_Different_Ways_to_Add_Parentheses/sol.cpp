#include "../include/header.h"

/*
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
*/

class Solution {
public:
    unordered_map<string, vector<int> > mp;

    vector<int> diffWaysToCompute(string input) {
        if(mp.find(input) != mp.end())
        {
            return mp[input];
        }

        vector<int> ret;
        if(0 == input.length())
        {
            return ret;
        }

        for(int i = 0; i < input.length(); ++i)
        {
            char c = input[i];
            if('*' == c || '+' == c || '-' == c)
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i + 1));
                for(int l : left)
                {
                    for(int r : right)
                    {
                        if('+' == c)
                        {
                            ret.push_back(l + r);
                        }
                        else if('-' == c)
                        {
                            ret.push_back(l - r);
                        }
                        else if('*' == c)
                        {
                            ret.push_back(l * r);
                        }
                    }
                }
            }
        }

        if(0 == ret.size())
        {
            ret.push_back(stoi(input, nullptr, 0));
        }
        mp[input] = ret;

        return ret;
    }
};

int main()
{
    return 0;
}


