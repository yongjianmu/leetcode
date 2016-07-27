#include "../include/header.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* p = root;
        TreeNode* first_err = NULL, * second_err = NULL;
        TreeNode* last = NULL;
        stack<TreeNode*> st;

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
                if(NULL != last && last->val > node->val)
                {
                    if(NULL == first_err)
                    {
                        first_err = last;
                        second_err = node;
                    }
                    else
                    {
                        second_err = node;
                    }
                }
                last = node;
                p = node->right;
            }
        }

        swap(first_err->val, second_err->val);
    }
};

int main()
{
    TreeNode* root = new TreeNode(2);
    TreeNode* right = new TreeNode(1);
    root->right = right;

    Solution sol;
    sol.recoverTree(root);

    return 0;
}
