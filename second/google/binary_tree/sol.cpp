#include "../../include/header.h"

class Solution
{
public:
    string mRet;
    TreeNode* mRoot;

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

    void dfs(TreeNode* root, string& cur)
    {
        char c = 'a' + root->val;
        cur.push_back(c);
        if(NULL == root->left && NULL == root->right)
        {
            if(mRet.length() == 0)
            {
                mRet = cur;
            }
            else
            {
                mRet = mRet > cur ? cur : mRet;
            }
        }

        if(NULL != root->left)
        {
            dfs(root->left, cur);
        }
        if(NULL != root->right)
        {
            dfs(root->right, cur);
        }

        cur.pop_back();
    }

    string findPath(TreeNode* root)
    {
        if(NULL == root)
        {
            return "";
        }

        mRet = "";
        string cur = "";
        dfs(root, cur);
        return mRet;
    }
};


int main()
{
    vector<int> input = {1,2,3,4,5,6,7,8};
    Solution sol;
    TreeNode* tree = sol.createBSTTree(input);
    string result = sol.findPath(tree);
    printResult();
    cout << result << endl;

    return 0;
}

