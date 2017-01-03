#include "../include/header.h"

class Solution {
public:
    string parseTernary(string expression) {
        cout << expression << endl;
        int pos = expression.find_last_of('?');
        if(pos == string::npos) return expression;
        
        char condition = expression[pos - 1];
        int brChar = expression.find_first_of(':', pos);
        char brTrue = expression[brChar - 1], brFalse = expression[brChar + 1];
        expression.erase(pos - 1, brChar + 3 - pos);
        if('T' == condition)
        {
            expression.insert(pos - 1, 1, brTrue);
        }
        else
        {
            expression.insert(pos - 1, 1, brFalse);
        }
        return parseTernary(expression);
    }
};

int main()
{
    string input = "T?T?F?7:T?T?F?3:F?T?0:1:0:6:1:0:5";
    Solution sol;
    string result = sol.parseTernary(input);
    printResult();
    cout << result << endl;
    return 0;
}
