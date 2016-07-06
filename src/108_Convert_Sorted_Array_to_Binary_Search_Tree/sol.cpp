#include <iostream>
#include <vector>

using namespace std;


// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int L, int R)
    {
        if(0 == nums.size())
        {
            return NULL;
        }

        if(L > R)
        {
            return NULL;
        }

        TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
        if(L == R)
        {
            root->val = nums[L];
            return root;
        }

        int mid = (R - L) >> 1;
        root->val = nums[mid];

        root->left = dfs(nums, L, mid - 1);
        root->right = dfs(nums, mid + 1, R);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
};

void pre_order(TreeNode* root)
{
    if(NULL == root)
    {
        return;
    }

    cout << root->val << endl;
    pre_order(root->left);
    pre_order(root->right);
}

int main()
{
    Solution sol;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);

    TreeNode* root = sol.sortedArrayToBST(v);
    pre_order(root);

    return 0;

}
