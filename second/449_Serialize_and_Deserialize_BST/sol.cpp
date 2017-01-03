#include "../include/header.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    queue<TreeNode*> mQueue;

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if(NULL == root) return ret;
        ret += to_string(root->val) + " ";
        mQueue.push(root);
        while(!mQueue.empty())
        {
            TreeNode* node = mQueue.front(); mQueue.pop();
            if(NULL == node->left) ret += "# ";
            else {ret += to_string(node->left->val) + " "; mQueue.push(node->left);}
            if(NULL == node->right) ret += "# ";
            else {ret += to_string(node->right->val) + " "; mQueue.push(node->right);}
        }
        //auto end = ret.find_last_of("1234567890");
        //return ret.substr(0, end + 2);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data.length() == 0) return root;
        auto iter = data.begin();
        size_t start = 0;
        auto pos = data.find_first_of(" ");
        root = new TreeNode(stoi(data.substr(start, pos - start)));
        start = pos + 1;
        mQueue.push(root);
        while(!mQueue.empty())
        {
            TreeNode* node = mQueue.front(); mQueue.pop();
            pos = data.find_first_of(" ", pos + 1);
            string sub = data.substr(start, pos - start);
            cout << sub << endl;
            start = pos + 1;
            if(sub.length() > 0 && "#" != sub)
            {
                node->left = new TreeNode(stoi(sub));
                mQueue.push(node->left);
            }
            pos = data.find_first_of(" ", pos + 1);
            sub = data.substr(start, pos - start);
            cout << sub << endl;
            start = pos + 1;
            
            if(sub.length() > 0 && "#" != sub)
            {
                node->right = new TreeNode(stoi(sub));
                mQueue.push(node->right);
            }
        }
        return root;
    }
};

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
    TreeNode* mRoot = createBSTNode(vec, 0, size - 1);
    return mRoot;
}


int main()
{
    vector<int> nums = {1,2,3};
    TreeNode* root = createBSTTree(nums);
    Codec codec;
    string encode = codec.serialize(root);
    cout << encode << endl;
    TreeNode* decode = codec.deserialize(encode);

    return 0;
}
