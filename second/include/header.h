#ifndef __HEADER_H__
#define __HEADER_H__

#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <functional>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <random>
#include <assert.h>

using namespace std;


/**********************************************************************
 * Tree Node functions
 **********************************************************************/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

void deleteTree(TreeNode* head, bool print_flag = false)
{
    queue<TreeNode*> q;
    if(NULL != head)
    {
        q.push(head);
    }

    while(!q.empty())
    {
        TreeNode* del = q.front();
        q.pop();
        if(print_flag)
        {
            cout << del->val << ", ";
        }
        if(NULL != del->left)
        {
            q.push(del->left);
        }
        if(NULL != del->right)
        {
            q.push(del->right);
        }
        delete del;
    }
    cout << endl;
}

/**********************************************************************
 * List Node functions
 **********************************************************************/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(vector<int> input)
{
    int size = input.size();
    if(0 == size)
    {
        return NULL;
    }

    ListNode* head = new ListNode(input[0]);
    ListNode* p = head;
    for(int i = 1; i < size; ++i)
    {
        ListNode* node = new ListNode(input[i]);
        p->next = node;
        p = p->next;
    }

    return head;
}

void deleteList (ListNode* head, bool need_print = false)
{
    while(NULL != head)
    {
        ListNode* del = head;
        head = head->next;
        if(need_print)
        {
            cout << del->val << ", ";
        }
        delete del;
    }
    cout << endl;
}

/**********************************************************************
 * Print functions
 **********************************************************************/

void printResult()
{
    cout << "#### Result ####" << endl;
}

template <class T>
void printVector1D(vector<T> vec, bool separate_line = false)
{
    cout << "#### Vector ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(separate_line)
        {
            cout << vec[i] << endl;
        }
        else
        {
            cout << vec[i] << ", ";
        }
    }
    cout << endl;
}

template <class T>
void printVector2D(vector<vector<T> > vec, bool separate_line = false)
{
    cout << "#### Vector ####" << endl;
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].size(); ++j)
        {
            if(separate_line)
            {
                cout << vec[i][j] << endl;
            }
            else
            {
                cout << vec[i][j] << ", ";
            }
        }
        cout << "#####################" << endl;
    }
}

#endif
