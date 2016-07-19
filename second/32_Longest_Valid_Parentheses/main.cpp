#include "../include/header.h"

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> q;
        int len = s.length();
        bool *match = new bool[len];

        for (int i = 0; i < len; i++){
            match[i] = 0;
            if (s[i] == ')' && !q.empty()){
                match[q.top()] = match[i]=true;
                q.pop();
            }
            else if (s[i] == '(')
                q.push(i);
        }

        int temp = 0, ans = 0;
        for (int i = 0; i < len; i++){
            if (!match[i])	{ temp = 0; continue; }
            temp++;
            ans = ans < temp ? temp : ans;
        }

        delete[] match;
        return ans;

    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}