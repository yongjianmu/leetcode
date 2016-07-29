#include "../include/header.h"


class Solution {
public:
    int mRet;

    int solve(TreeNode* root)
    {
        if(NULL == root)
        {
            return 0;
        }

        int L = solve(root->left), R = solve(root->right);
        mRet = max(mRet, L + R + root->val);
        mRet = max(mRet, max(L, R) + root->val);
        mRet = max(mRet, root->val);
        return max(max(L, R) + root->val, root->val);
    }

    int maxPathSum(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }

        mRet = INT_MIN;
        solve(root);
        return mRet;
    }
};
