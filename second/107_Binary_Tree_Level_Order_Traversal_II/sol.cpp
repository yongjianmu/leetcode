#include "../include/header.h"

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ret;
        if(NULL == root)
        {
            return ret;
        }

        queue<TreeNode*> q1, q2;
        q1.push(root);
        while(!q1.empty())
        {
            vector<int> cur;
            while(!q1.empty())
            {
                TreeNode* node = q1.front();
                q1.pop();
                cur.push_back(node->val);

                if(NULL != node->left)
                {
                    q2.push(node->left);
                }
                if(NULL != node->right)
                {
                    q2.push(node->right);
                }
            }
            ret.insert(ret.begin(), cur); 
            q1.swap(q2);
        }
        return ret;
    }
};
