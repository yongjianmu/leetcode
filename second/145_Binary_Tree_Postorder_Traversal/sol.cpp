#include "../include/header.h"


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(NULL == root)
        {
            return ret;
        }

        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* node = st1.top();
            st1.pop();
            //st2.push(node);
            ret.insert(ret.begin(), node->val);
            if(NULL != node->left)
            {
                st1.push(node->left);
            }
            if(NULL != node->right)
            {
                st1.push(node->right);
            }
        }

        //while(!st2.empty())
        //{
        //    ret.push_back(st2.top()->val);
        //    st2.pop();
        //}

        return ret;
    }
};
