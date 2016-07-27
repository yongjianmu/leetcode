#include "../include/header.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(NULL == root)
        {
            return true;
        }

        TreeNode* p = root;
        stack<TreeNode*> st;
        long long last = LONG_MIN;

        while(NULL != p || !st.empty())
        {
            if(NULL != p)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                TreeNode* node = st.top();
                st.pop();
                if(node->val <= last)
                {
                    return false;
                }
                last = node->val;
                p = node->right;
            }
        }
        return true;
    }
};
