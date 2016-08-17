#include "../include/header.h"

/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/

void strSplit(string s, char delim, vector<string>& vec)
{
    stringstream ss(s);
    string cur;

    while(getline(ss, cur, delim))
    {
        vec.push_back(cur);
    }
}

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int len = preorder.length();
        if(0 == len)
        {
            return false;
        }
        else if('#' == preorder[0])
        {
            return 1 == len;
        }

        vector<string> str;
        strSplit(preorder, ',', str);
        int size = str.size();

        queue<string> q1, q2;
        q1.push(str[0]);
        int pos = 1;
        while(!q1.empty() && pos < size)
        {
            while(!q1.empty())
            {
                string cur = q1.front();
                q1.pop();
                if(pos >= size)
                {
                    return false;
                }

                if("#" != str[pos])
                {
                    q2.push(str[pos]);
                }
                ++pos;

                if(pos >= size)
                {
                    return false;
                }
                if("#" != str[pos])
                {
                    q2.push(str[pos]);
                }
                ++pos;
            }
            q1.swap(q2);
        }

        if(!q1.empty())
        {
            return false;
        }

        return pos >= size;
    }
};

int main()
{
    string input = "1";
    Solution sol;
    bool result = sol.isValidSerialization(input);
    printResult();
    cout << result << endl;

    return 0;
}
