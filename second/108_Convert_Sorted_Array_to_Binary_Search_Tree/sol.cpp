#include "../include/header.h"

class Solution {
public:

    TreeNode* createTree(int start, int end, vector<int>& nums)
    {
        int mid = start + ((end - start) >> 1);
        TreeNode* root = new TreeNode(nums[mid]);
        if(start < mid)
        {
            root->left = createTree(start, mid - 1, nums);
        }
        if(end > mid)
        {
            root->right = createTree(mid + 1, end, nums);
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(0 == size)
        {
            return NULL;
        }
        return createTree(0, size - 1, nums);
    }
};
