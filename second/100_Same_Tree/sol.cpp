#include "../include/header.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(NULL == p)
        {
            return NULL == q;
        }
        if(NULL == q)
        {
            return NULL == p;
        }

        stack<TreeNode*> stp, stq;
        stp.push(p);
        stq.push(q);
        while(!stp.empty() && !stq.empty())
        {
            TreeNode* nodep = stp.top(), * nodeq = stq.top();
            stp.pop();
            stq.pop();
            if(nodep->val != nodeq->val)
            {
                return false;
            }

            if(NULL != nodep->left)
            {
                stp.push(nodep->left);
                if(NULL == nodeq->left)
                {
                    return false;
                }
            }
            if(NULL != nodep->right)
            {
                stp.push(nodep->right);
                if(NULL == nodeq->right)
                {
                    return false;
                }
            }
            if(NULL != nodeq->left)
            {
                stq.push(nodeq->left);
                if(NULL == nodep->left)
                {
                    return false;
                }
            }
            if(NULL != nodeq->right)
            {
                stq.push(nodeq->right);
                if(NULL == nodep->right)
                {
                    return false;
                }
            }
        }

        return stp.empty() && stq.empty();
    }
};
