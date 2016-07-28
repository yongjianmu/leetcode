#include "../include/header.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
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
            q1.swap(q2);
        }
        return cnt;
    }
};
