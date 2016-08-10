#include "../include/header.h"


/*
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/


class Solution {
public:

    vector<string> solve(string num, int target)
    {
        vector<string> vec;
        int len = num.length();
        if(0 == len)
        {
            return vec;
        }

        for(int i = 1; i <= len; ++i)
        {
            if(i == len && stoi(num) == target)
            {
                if(0 == stoi(num))
                {
                    vec.push_back("0");
                }
                else
                {
                    vec.push_back(num);
                }
            }
            else
            {
                string left = num.substr(0, i);
                vector<string> right_add = solve(num.substr(i, len - i), target - stoi(left));
                vector<string> right_min = solve(num.substr(i, len - i), target + stoi(left));
                vector<string> right_mul;
                if(0 != stoi(left))
                {
                    right_mul = solve(num.substr(i, len - i), target / stoi(left));
                }

                for(int i = 0; i < right_add.size(); ++i)
                {
                    if(stoi(left) + stoi(right_add[i]) == target)
                    {
                        string cur;
                        cur = left + "+" + right_add[i];
                        vec.push_back(cur);
                    }
                }

                for(int i = 0; i < right_min.size(); ++i)
                {
                    if(stoi(left) - stoi(right_min[i]) == target)
                    {
                        string cur;
                        cur = left + "-" + right_min[i];
                        vec.push_back(cur);
                    }
                }

                for(int i = 0; i < right_mul.size(); ++i)
                {
                    if(0 != stoi(left))
                    {
                        if(stoi(left) * stoi(right_mul[i]) == target)
                        {
                            string cur;
                            if(0 == stoi(right_mul[i]))
                            {
                                cur = left + "*" + "0";
                            }
                            else
                            {
                                cur = left + "*" + right_mul[i];
                            }
                            vec.push_back(cur);
                        }
                    }
                    else
                    {
                        if(0 == target)
                        {
                            string cur;
                            cur = left + "*" + right_mul[i];
                            vec.push_back(cur);
                            if(0 == stoi(right_mul[i]))
                            {
                                cur = left + "+" + "0";
                                vec.push_back(cur);
                                cur = left + "-" + "0";
                                vec.push_back(cur);
                            }
                        }
                    }
                }
            }
        }
        return vec;
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ret;
        int len = num.length();
        if(0 == len)
        {
            return ret;
        }

        ret = solve(num, target);
        return ret;
    }
};


int main()
{
    string input = "000";
    int target = 0;
    Solution sol;
    vector<string> result = sol.addOperators(input, target);
    cout << "#### Result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}
