#include "../include/header.h"


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* p = root;
        stack<TreeNode*> st;
        int cnt = 0;
        int ret = 0;
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
                ++cnt;
                if(cnt == k)
                {
                    ret = node->val;
                    break;
                }
                st.pop();
                p = node->right;
            }
        }
        return ret;
    }
};
