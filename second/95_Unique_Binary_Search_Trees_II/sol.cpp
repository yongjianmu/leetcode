#include "../include/header.h"

/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:

    vector<TreeNode*> createTree(int start, int end)
    {
        vector<TreeNode*> ret;
        if(start > end)
        {
            return ret;
        }

        for(int i = start; i <= end; ++i)
        {
            vector<TreeNode*> left = solve(start, i - 1);
            vector<TreeNode*> right = solve(i + 1, end);

            if(0 != left.size() && 0 != right.size())
            {
                for(int l = 0; l < left.size(); ++l)
                {
                    for(int r = 0; r < right.size(); ++r)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[l];
                        root->right = right[r];
                        ret.push_back(root);
                    }
                }
            }
            else if(0 == left.size() && 0 != right.size())
            {
                for(int r = 0; r < right.size(); ++r)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = NULL;
                    root->right = right[r];
                    ret.push_back(root);
                }
            }
            else if(0 != left.size() && 0 == right.size())
            {
                for(int l = 0; l < left.size(); ++l)
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = left[l];
                    root->right = NULL;
                    ret.push_back(root);
                }
            }
            else
            {
                TreeNode* root = new TreeNode(i);
                ret.push_back(root);
            }
        }
        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(0 == n)
        {
            return ret;
        }

        return solve(1, n);
    }
};
