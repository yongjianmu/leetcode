#include "../include/header.h"

TreeNode* maxDepthLCA_DFS(TreeNode* root, int& depth)
{
    if(NULL == root)
    {
        depth = 0;
        return NULL;
    }

    int ldepth = 0, rdepth = 0;
    TreeNode* lchild = maxDepthLCA_DFS(root->left, ldepth);
    TreeNode* rchild = maxDepthLCA_DFS(root->right, rdepth);
    depth = max(ldepth + rdepth) + 1;

    if(ldepth == rdepth) return root;
    return ldepth > rdepth ? lchild : rchild;
}

int maxDepthLCA(TreeNode* root)
{
    int depth = 0;
    TreeNode* ret = LCA_DFS(root, depth);
    return ret->val;
}



TreeNode* nodesLCA_DFS(TreeNode* root, TreeNode* q, TreeNode* p)
{
    if(NULL == root) return NULL;
    
    if(root == q || root == p) return root;
    TreeNode* left = nodesLCA_DFS(root->left, q, p);
    TreeNode* right = nodesLCA_DFS(root->right, q, p);

    if(NULL != left && NULL != right) return root;
    return left == NULL ? right : left;
}
