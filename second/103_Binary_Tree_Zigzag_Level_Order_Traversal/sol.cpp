#include "../include/header.h"

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ret;
        if(NULL == root)
        {
            return ret;
        }

        queue<TreeNode*> q1, q2;
        q1.push(root);
        int cnt = 0;
        while(!q1.empty())
        {
            vector<int> cur;
            while(!q1.empty())
            {
                TreeNode* node = q1.front();
                q1.pop();
                if(0 == cnt % 2)
                {
                    cur.push_back(node->val);
                }
                else
                {
                    cur.insert(cur.begin(), node->val);
                }

                if(NULL != node->left)
                {
                    q2.push(node->left);
                }
                if(NULL != node->right)
                {
                    q2.push(node->right);
                }
            }
            ++cnt;
            ret.push_back(cur);
            q1.swap(q2);
        }
        return ret;
    }
};
