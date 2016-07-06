#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


/*
        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(NULL == root)
        {
            return;
        }

        queue<TreeLinkNode*> q1;
        queue<TreeLinkNode*> q2;

        q1.push(root);

        while(!q1.empty())
        {
            TreeLinkNode* head= q1.front();
            q1.pop();
            if(NULL != head->left)
            {
                q2.push(head->left);
            }
            if(NULL != head->right)
            {
                q2.push(head->right);
            }

            while(!q1.empty())
            {
                TreeLinkNode* node = q1.front();
                q1.pop();
                head->next = node;
                head = node;

                if(NULL != node->left)
                {
                    q2.push(node->left);
                }
                if(NULL != node->right)
                {
                    q2.push(node->right);
                }
            }
            head->next = NULL;

            swap(q1, q2);
        }
    }
};
