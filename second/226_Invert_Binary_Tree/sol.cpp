#include "../include/header.h"

/*
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(NULL == root)
        {
            return NULL;
        }

        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;

        if(NULL != root->left)
        {
            root->left = invertTree(root->left);
        }

        if(NULL != root->right)
        {
            root->right= invertTree(root->right);
        }

        return root;
    }
};
