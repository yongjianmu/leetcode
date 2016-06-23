#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


/*
        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(NULL == root)
        {
            return root;
        }

        queue<TreeLinkNode*> q1;
        queue<TreeLinkNode*> q2;

        q1.push(root);

        while(!q1.empty())
        {
        }
    }
};
