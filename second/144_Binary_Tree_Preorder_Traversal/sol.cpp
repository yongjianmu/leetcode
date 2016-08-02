#include "../include/header.h"


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(NULL == root)
        {
            return ret;
        }

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            ret.push_back(node->val);
            if(NULL != node->right)
            {
                st.push(node->right);
            }
            if(NULL != node->left)
            {
                st.push(node->left);
            }
        }
        return ret;
    }
};
