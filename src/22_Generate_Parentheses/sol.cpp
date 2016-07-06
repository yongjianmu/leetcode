#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void recursive_generate(vector<string>& ret, string curr, int left_p, int n)
    {
        if(0 == left_p && 0 == n)
        {
            ret.push_back(curr);
            return;
        }

        if(0 < left_p)
        {
            curr.push_back('(');
            recursive_generate(ret, curr, left_p - 1, n);
            curr.pop_back();
        }

        if(left_p < n)
        {
            curr.push_back(')');
            recursive_generate(ret, curr, left_p, n - 1);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) 
    {
        vector<string> ret;
        if(0 == n)
        {
            return ret;
        }
        string curr;
        curr.reserve(2 * n);

        recursive_generate(ret, curr, n, n);
        return ret;
    }
};

int main()
{
    int n = 3;
    Solution sol;
    vector<string> result = sol.generateParenthesis(n);
    vector<string>::iterator iter;
    for(iter = result.begin(); iter != result.end(); ++iter)
    {
        cout << *iter << endl;
    }
    return 0;
}
