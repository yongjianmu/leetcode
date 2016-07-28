#include "../include/header.h"


class Solution {
public:

    int solve(TreeNode* root, int depth)
    {
        if(NULL == root)
        {
            return depth;
        }

        int L = solve(root->left, depth + 1);
        int R = solve(root->right, depth + 1);

        if(0 > L || 0 > R || 1 < abs(L - R))
        {
            return -1;
        }

        return max(L, R);
    }

    bool isBalanced(TreeNode* root) {
        if(-1 == solve(root, 0))
        {
            return false;
        }

        return true;
    }
};
