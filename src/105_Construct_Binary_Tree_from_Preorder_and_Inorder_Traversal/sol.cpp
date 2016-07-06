#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start_pre, int end_pre, int start_in, int end_in)
    {
        if(start_pre > end_pre)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[start_pre]);
        vector<int>::iterator iter;
        iter = find(inorder.begin(), inorder.end(), preorder[start_pre]);
        int index = distance(inorder.begin(), iter);
        TreeNode* left = solve(preorder, inorder, start_pre + 1, start_pre + index - start_in, start_in, index - 1);
        TreeNode* right = solve(preorder, inorder, start_pre + index - start_in + 1, end_pre, index + 1, end_in);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len_pre = preorder.size();
        int len_in = inorder.size();
        if(0 == len_pre || 0 == len_in)
        {
            return NULL;
        }

        return solve(preorder, inorder, 0, len_pre - 1, 0, len_in - 1);
    }
};
