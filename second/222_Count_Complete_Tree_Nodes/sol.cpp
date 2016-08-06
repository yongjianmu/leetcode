#include "../include/header.h"


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }

        int dep_left = 0, dep_right = 0;

        for(TreeNode* node = root; NULL != node; node = node->left)
        {
            ++dep_left;
        }

        for(TreeNode* node = root; NULL != node; node = node->right)
        {
            ++dep_right;
        }

        return dep_left == dep_right ? (1 << dep_left) - 1 : countNodes(root->left) + countNodes(root->right) + 1;
    }
};
