#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(NULL == root)
        {
            return 0;
        }

        int dep_left = 0, dep_right = 0;

        for(TreeNode* node = root; NULL != node; node = node->left)
        {
            ++dep_left;
        }

        for(TreeNode* node = root; NULL != node; node = node->right)
        {
            ++dep_right;
        }

        return dep_left == dep_right? (1 << dep_left) - 1 : countNodes(root->left) + countNodes(root->right) + 1;
    }
};


int main()
{
	Solution sol;
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->val = 1;
	root->left = NULL;
	root->right = NULL;

	cout << sol.countNodes(root) << endl;

	return 0;
}
