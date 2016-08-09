#include "../include/header.h"

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

class Solution {
public:
    void findAncestor(TreeNode* root, TreeNode* node, vector<TreeNode*>& ancestor, bool& found)
    {
        if(found)
        {
            return;
        }

        ancestor.push_back(root);
        if(root == node)
        {
            found = true;
            return;
        }

        if(NULL != root->left)
        {
            findAncestor(root->left, node, ancestor, found);
        }
        if(found)
        {
            return;
        }

        if(NULL != root->right)
        {
            findAncestor(root->right, node, ancestor, found);
        }
        if(found)
        {
            return;
        }

        ancestor.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> fp, fq;
        bool found_p = false, found_q = false;
        findAncestor(root, p, fp, found_p);
        findAncestor(root, q, fq, found_q);
        if(!found_p || !found_q)
        {
            return NULL;
        }

        int size_p = fp.size(), size_q = fq.size();
        TreeNode* ret = NULL;
        for(int i = 0; i < min(size_p, size_q); ++i)
        {
            if(fp[i] == fq[i])
            {
                ret = fp[i];
            }
        }

        return ret;
    }
};
