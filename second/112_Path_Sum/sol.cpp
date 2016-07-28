#include "../include/header.h"


/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

class Solution {
public:
    bool mRet;

    void solve(TreeNode* root, int cur, int sum)
    {
        if(mRet)
        {
            return;
        }

        int value = cur + root->val;
        if(NULL == root->left && NULL == root->right)
        {
            if(value == sum)
            {
                mRet = true;
                return;
            }
        }

        if(NULL != root->left)
        {
            solve(root->left, value, sum);
        }

        if(NULL != root->right)
        {
            solve(root->right, value, sum);
        }
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(NULL == root)
        {
            return false;
        }

        mRet = false;
        solve(root, 0, sum);
        return mRet;
    }
};
