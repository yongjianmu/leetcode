#include "../include/header.h"

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

class Solution {
public:
    int mRet;

    void solve(TreeNode* root, int cur)
    {
        int value = cur * 10 + root->val;
        if(NULL == root->right && NULL == root->left)
        {
            mRet += value;
        }

        if(NULL != root->left)
        {
            solve(root->left, value);
        }
        if(NULL != root->right)
        {
            solve(root->right, value);
        }
    }

    int sumNumbers(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }

        mRet = 0;
        solve(root, 0);
        return mRet;
    }
};
