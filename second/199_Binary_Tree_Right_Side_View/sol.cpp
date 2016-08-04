#include "../include/header.h"


/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(NULL == root)
        {
            return ret;
        }

        queue<TreeNode*> q1, q2;
        q1.push(root);
        while(!q1.empty())
        {
            while(!q1.empty())
            {
                TreeNode* node = q1.front();
                q1.pop();
                if(NULL != node->left)
                {
                    q2.push(node->left);
                }
                if(NULL != node->right)
                {
                    q2.push(node->right);
                }
                if(q1.empty())
                {
                    ret.push_back(node->val);
                }
            }
            q1.swap(q2);
        }
        return ret;
    }
};
