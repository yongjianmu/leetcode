#include "../include/header.h"

/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", 
*/

void split(string src, char delim, vector<string>& vec)
{
    string cur;
    stringstream ss(src);
    while(!getline(ss, cur, delim))
    {
        vec.push_back(cur);
    }
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret = "";
        if(NULL == root)
        {
            return ret;
        }

        queue<TreeNode*> q1, q2;
        q1.push(root);
        stringstream ss;
        ss << root->val;
        ss >> ret;
        while(!q1.empty())
        {
            while(!q1.empty())
            {
                TreeNode* node = q1.front();
                q1.pop();

                if(NULL != node->left)
                {
                    q2.push(node->left);
                    ss << ",";
                    ss << node->left->val;
                    ss >> ret;
                }
                else
                {
                    ss << ",null";
                    ss >> ret;
                }
                
                if(NULL != node->right)
                {
                    q2.push(node->right);
                    ss << ",";
                    ss << node->right->val;
                    ss >> ret;
                }
                else
                {
                    ss << ",null";
                    ss >> ret;
                }
            }
            q1.swap(q2);
        }

        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> value;
        split(data, ',', value);
        int size = value.size();
        if(0 == size)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(value[0]));
        queue<TreeNode*> q1, q2;
        q1.push(root);
        int index = 1;

        while(!q1.empty())
        {
            while(!q1.empty())
            {
                TreeNode* node = q1.front();
                q1.pop();
                if(index < size)
                {
                    if("null" == value[index])
                    {
                        node->left = NULL;
                    }
                    else
                    {
                        TreeNode* new_node = new TreeNode(stoi(value[index]));
                        node->left = new_node;
                        q2.push(new_node);
                    }
                    ++index;
                }

                if(index < size)
                {
                    if("null" == value[index])
                    {
                        node->right= NULL;
                    }
                    else
                    {
                        TreeNode* new_node = new TreeNode(stoi(value[index]));
                        node->right = new_node;
                        q2.push(new_node);
                    }
                    ++index;
                }
            }
            q1.swap(q2);
        }

        return root;
    }
};
