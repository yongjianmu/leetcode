#include "../include/header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int solve(TreeNode* root)
    {
        if(NULL == root)
        {
            return 0;
        }

        int cur = root->val;
        int next = 0;
        if(NULL != root->left)
        {
            cur += solve(root->left->left);
            cur += solve(root->left->right);

            next += solve(root->left);
        }

        if(NULL != root->right)
        {
            cur += solve(root->right->left);
            cur += solve(root->right->right);

            next += solve(root->right);
        }


        return max(cur, next);
    }

    int rob(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }

        return solve(root);
    }
};
