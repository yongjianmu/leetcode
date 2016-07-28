#inclue "../include/header.h"


/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

class Solution {
public:

    void flatten(TreeNode* root) {
        if(NULL == root)
        {
            return;
        }

        TreeNode* p = root;
        TreeNode* L = p->left, * R = p->right;
        flatten(L);
        p->left = NULL;
        p->right = L;
        while(NULL != p->right)
        {
            p = p->right;
        }
        flatten(R);
        p->right = R;
    }
};
