#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if(NULL == l1 && NULL == l2)
		{
			return NULL;
		}

        ListNode* ret = new ListNode(0);
        ListNode* tail = ret;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
        int carry = 0;

		if(NULL != p1)
		{
			ret->val += p1->val;
			p1 = p1->next;
		}

		if(NULL != p2)
		{
			ret->val += p2->val;
			p2 = p2->next;
		}

		if(10 <= ret->val)
		{
			ret->val %= 10;
			carry = 1;
		}

        while(NULL != p1 || NULL != p2)
        {
            ListNode* node = new ListNode(carry);
            if(NULL != p1)
            {
                node->val += p1->val;
                p1 = p1->next;
            }

            if(NULL != p2)
            {
                node->val += p2->val;
                p2 = p2->next;
            }

            if(10 <= node->val)
            {
                node->val %= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            tail->next = node;
			tail = node;
        }

        if(1 == carry)
        {
            ListNode* node = new ListNode(carry);
            tail->next = node;
            tail = node;
        }

        return ret;
    }
};

int main()
{
	int arr1[3] = {2, 4, 3};
	int arr2[3] = {5, 6, 4};
	ListNode* l1 = new ListNode(arr1[0]);
	ListNode* p1 = l1;
	ListNode* l2 = new ListNode(arr2[0]);
	ListNode* p2 = l2;

	for(int i = 1; i < 3; ++i)
	{
		ListNode* node1 = new ListNode(arr1[i]);
		ListNode* node2 = new ListNode(arr2[i]);

		p1->next = node1;
		p1 = node1;

		p2->next = node2;
		p2 = node2;
	}

	cout << "------- Sol ----------" << endl;
	Solution sol;
	ListNode* ret = sol.addTwoNumbers(l1, l2);
	ListNode* ptr = ret;
	while(NULL != ptr)
	{
		cout << ptr->val << endl;
		ptr = ptr->next;
	}

	cout << "-------- p1 --------" << endl;
	p1 = l1;
	while(NULL != p1)
	{
		cout << p1->val << endl;
		p1 = p1->next;
	}

	cout << "-------- p2 --------" << endl;
	p2 = l2;
	while(NULL != p2)
	{
		cout << p2->val << endl;
		p2 = p2->next;
	}

	return 0;
}
