#include "../include/header.h"

class Solution {
public:

    TreeNode* createTree(int pre_start, int pre_end, vector<int>& preorder, \
                        int in_start, int in_end, vector<int>& inorder \
                )
    {
        if(pre_start > pre_end)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[pre_start]);
        auto iter = find(inorder.begin(), inorder.end(), preorder[pre_start]);
        int index = distance(inorder.begin(), iter);
        TreeNode* left = createTree(pre_start + 1, pre_start + index - in_start, preorder, in_start, index - 1, inorder);
        TreeNode* right = createTree(pre_start + index - in_start + 1, pre_end, preorder, index + 1, in_end, inorder);
        root->left = left;
        root->right = right;

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if(0 == size)
        {
            return NULL;
        }

        return createTree(0, size - 1, preorder, 0, size - 1, inorder);
    }
};

int main()
{
    vector<int> preorder = {4, 3, 1, 2};
    vector<int> inorder = {1, 2, 3, 4};
    Solution sol;
    TreeNode* result = sol.buildTree(preorder, inorder);
    printResult();
    deleteTree(result, true);

    return 0;
}
