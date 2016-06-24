#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int mRet;

    int solve(TreeNode* root)
    {
        if(NULL == root)
        {
            return -1;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        int tmp = left + right + root->val;
        mRet = max(mRet, tmp);
        tmp = max(left, right) + root->val;
        mRet = max(mRet, tmp);
        mRet = max(mRet, root->val);
        return max(max(left, right) + root->val, root->val);
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
