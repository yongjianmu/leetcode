#include "../include/header.h"

/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

class Solution {
public:
    int rob(TreeNode* root) 
    {
        return dfs(root).first;
    }
    
    pair<int, int> dfs(TreeNode* root)
    {
        pair<int, int> dp = make_pair(0,0);
        if(root)
        {
            pair<int, int> dp_L = dfs(root->left);
            pair<int, int> dp_R = dfs(root->right);
            dp.second = dp_L.first + dp_R.first;
            dp.first = max(dp.second ,dp_L.second + dp_R.second + root->val);
        }
        return dp;
    }
};
