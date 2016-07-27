#include "../include/header.h"

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool mRet;

    void solve(TreeNode* left, TreeNode* right)
    {
        if(!mRet)
        {
            return;
        }

        if(NULL == left && NULL == right)
        {
            mRet = true;
            return;
        }

        if(NULL == left || NULL == right)
        {
            mRet = false;
            return;
        }

        if(left->val != right->val)
        {
            mRet = false;
            return;
        }

        solve(left->left, right->right);
        solve(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(NULL == root)
        {
            return true;
        }

        if(NULL == root->left)
        {
            return NULL == root->right;
        }
        if(NULL == root->right)
        {
            return NULL == root->left;
        }

        mRet = true;
        solve(root->left, root->right);
        return mRet;
    }
};
