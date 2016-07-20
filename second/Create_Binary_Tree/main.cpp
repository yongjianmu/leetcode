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

    void preOrderWithLevel(TreeNode* root, vector<vector<int> >& vec)
    {
        if(NULL == root)
        {
            return;
        }

        queue<TreeNode*> q1, q2;
        q1.push(root);

        while(!q1.empty())
        {
            vector<int> cur;
            while(!q1.empty())
            {
                TreeNode* p = q1.front();
                q1.pop();
                if(NULL != p->left)
                {
                    q2.push(p->left);
                }
                if(NULL != p->right)
                {
                    q2.push(p->right);
                }
                cur.push_back(p->val);
            }
            vec.push_back(cur);
            q1.swap(q2);
        }
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

    void inOrderNonRec(TreeNode* root, vector<int>& vec)
    {
        if(NULL == root)
        {
            return;
        }

        TreeNode* p = root;
        stack<TreeNode*> st;
        while(!st.empty() || NULL != p)
        {
            if(NULL != p)
            {
                st.push(p);
                p = p->left;
            }
            else
            {
                p = st.top();
                st.pop();
                vec.push_back(p->val);
                p = p->right;
            }
        }
    }

    void postOrderRec(TreeNode* root, vector<int>& vec)
    {
        if(NULL != root->left)
        {
            postOrderRec(root->left, vec);
        }

        if(NULL != root->right)
        {
            postOrderRec(root->right, vec);
        }

        vec.push_back(root->val);
    }

    void postOrderNonRec(TreeNode* root, vector<int>& vec)
    {
        if(NULL == root)
        {
            return;
        }

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while(!st1.empty())
        {
            TreeNode* p = st1.top();
            st1.pop();
            st2.push(p);
            if(NULL != p->left)
            {
                st1.push(p->left);
            }
            if(NULL != p->right)
            {
                st1.push(p->right);
            }
        }

        while(!st2.empty())
        {
            vec.push_back(st2.top()->val);
            st2.pop();
        }
    }

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

    vector<vector<int> > preOderTraverseWithLevel()
    {
        vector<vector<int> > ret;
        if(NULL == mRoot)
        {
            return ret;
        }

        preOrderWithLevel(mRoot, ret);
        return ret;
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
        else
        {
            inOrderNonRec(mRoot, ret);
        }

        return ret;
    }

    vector<int> postOrderTraverse(bool isRecursive)
    {
        vector<int> ret;
        if(NULL == mRoot)
        {
            return ret;
        }

        if(isRecursive)
        {
            postOrderRec(mRoot, ret);
        }
        else
        {
            postOrderNonRec(mRoot, ret);
        }

        return ret;
    }
};

int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    BinaryTree bt;
    bt.createBSTTree(input);
    vector<vector<int> > result = bt.preOderTraverseWithLevel();
    cout << "#### preOrder result ####" << endl;
    for(int i = 0; i < result.size(); ++i)
    {
        for(int j = 0; j < result[i].size(); ++j)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}