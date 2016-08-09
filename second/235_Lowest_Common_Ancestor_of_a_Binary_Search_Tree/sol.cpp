#include "../include/header.h"

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(NULL == root)
        {
            return NULL;
        }

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            if(node->val == p->val || node->val == q->val)
            {
                return node;
            }

            if(0 > (node->val - p->val) * (node->val - q->val))
            {
                return node;
            }

            if(node->val > p->val && node->val > q->val)
            {
                st.push(node->left);
            }
            else if(node->val < p->val && node->val < q->val)
            {
                st.push(node->right);
            }
        }

        return NULL;
    }
};
