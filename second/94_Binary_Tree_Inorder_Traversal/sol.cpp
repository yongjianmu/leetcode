#include "../include/header.h"


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(NULL == root)
        {
            return ret;
        }

        TreeNode* p = root;
        stack<TreeNode*> st;
        while(!st.empty() || NULL != p)
        {
            if(NULL != p)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                ListNode* node = st.top();
                ret.push_back(node->val);
                st.pop();
                p = node->right;
            }
        }
        return ret;
    }
};
