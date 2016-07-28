#include "../include/header.h"

/*
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
Subscribe to see which companies asked this question
*/

class Solution {
public:
    void connect(TreeLinkNode *root) {
        while(NULL != root)
        {
            TreeLinkNode* p = root;
            while(NULL != p)
            {
                if(NULL != p->left)
                {
                    p->left->next = p->right;
                }

                if(NULL != p->right && NULL != p->next)
                {
                    p->right->next = p->next->left;
                }

                p = p->next;
            }
            root = root->left;
        }
    }
};
