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
#include <climits>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;



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

