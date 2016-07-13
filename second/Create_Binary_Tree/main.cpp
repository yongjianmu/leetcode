#include "../include/header.h"

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree
{
private:
    TreeNode* mRoot;

public:
    BinaryTree()
    {
        mRoot = NULL;
    }

    ~BinaryTree()
    {
        queue<TreeNode*> q;
        if(NULL != mRoot)
        {
            q.push(mRoot);
        }
        while(!q.empty())
        {
            TreeNode* del = q.front();
            if(NULL != del->left)
            {
                q.push(del->left);
            }
            if(NULL != del->right)
            {
                q.push(del->right);
            }
            q.pop();
            delete del;
        }
    }

    TreeNode* createBSTNode(vector<int> vec, int start, int end)
    {
        int mid = start + ((end - start)>> 1);
        TreeNode* root = new TreeNode(vec[mid]);

        if(start < mid)
        {
            root->left = createBSTNode(vec, start, mid - 1);
        }

        if(end > mid)
        {
            root->right = createBSTNode(vec, mid + 1, end);
        }
        return root;
    }

    TreeNode* createBSTTree(vector<int>& vec)
    {
        int size = vec.size();
        if(0 == size)
        {
            return NULL;
        }

        sort(vec.begin(), vec.end());
        mRoot = createBSTNode(vec, 0, size - 1);
        return mRoot;
    }

    void inOrderRec(TreeNode* root, vector<int>& vec)
    {
        if(NULL != root->left)
        {
            inOrderRec(root->left, vec);
        }

        vec.push_back(root->val);

        if(NULL != root->right)
        {
            inOrderRec(root->right, vec);
        }
    }

    vector<int> inOrderTraverse(bool isRecursive)
    {
        vector<int> ret;
        if(NULL == mRoot)
        {
            return ret;
        }

        if(isRecursive)
        {
            inOrderRec(mRoot, ret);
        }

        return ret;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    BinaryTree bt;
    bt.createBSTTree(input);
    vector<int> result = bt.inOrderTraverse(true);
    cout << "#### inOrder result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;

    return 0;
}