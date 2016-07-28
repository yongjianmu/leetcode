#include "../include/header.h"


/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
*/


class Solution {
public:
    vector<vector<int> > mRet;

    void solve(TreeNode* root, vector<int> cur, int value, int sum)
    {
        if(NULL == root->left && NULL == root->right)
        {
            if(value + root->val == sum)
            {
                cur.push_back(root->val);
                mRet.push_back(cur);
                cur.pop_back();
                return;
            }
        }
        
        if(NULL != root->left)
        {
            cur.push_back(root->val);
            solve(root->left, cur, value + root->val, sum);
            cur.pop_back();
        }
        if(NULL != root->right)
        {
            cur.push_back(root->val);
            solve(root->right, cur, value + root->val, sum);
            cur.pop_back();
        }
    }

    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        if(NULL == root)
        {
            return mRet;
        }

        vector<int> cur;
        solve(root, cur, 0, sum);
        return mRet;
    }
};
