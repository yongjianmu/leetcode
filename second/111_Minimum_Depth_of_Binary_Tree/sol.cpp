#include "../include/header.h"

class Solution {
public:
    int solve(TreeNode* root, int depth)
    {
        if(NULL == root->left && NULL == root->right)
        {
            return depth;
        }

        int L = INT_MAX, R = INT_MAX;
        if(NULL != root->left)
        {
            L = solve(root->left, depth + 1);
        }
        if(NULL != root->right)
        {
            R = solve(root->right, depth + 1);
        }

        return min(L, R);
    }

    int minDepth(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }

        return solve(root, 1);
    }
};
