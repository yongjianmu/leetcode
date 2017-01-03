#include "../../include/header.h"

class Solution
{
public:
    ListNode* plusOne(ListNode* head)
    {
        if(NULL == head)
        {
            return NULL;
        }

        ListNode* cur = head, * right = NULL;
        while(NULL != cur)
        {
            if(9 != cur->val)
            {
                right = cur;
            }
            cur = cur->next;
        }

        if(NULL == right)
        {
            right = new ListNode(0);
            right->next = head;
            head = right;
        }
        ++right->val;
        cur = right->next;
        while(NULL != cur)
        {
            cur->val = 0;
            cur = cur->next;
        }
        return head;
    }

    ListNode* plusTwoList(ListNode* list1, ListNode* list2)
    {
        // Make the two lists in equal length
        int cnt1 = 0, cnt2 = 0;
        ListNode* m1 = list1, * m2 = list2;
        while(NULL != m1 || NULL != m2)
        {
            if(NULL != m1)
            {
                m1 = m1->next, ++cnt1;
            }
            if(NULL != m2)
            {
                m2 = m2->next, ++cnt2;
            }
        }

        if(cnt1 != cnt2)
        {
            // Make list1 point to the shorter list
            if(cnt1 > cnt2)
            {
                ListNode* tmp = list1;
                list1 = list2;
                list2 = tmp;
            }

            for(int i = 0; i < cnt2 - cnt1; ++i)
            {
                ListNode* tmp = new ListNode(0);
                tmp->next = list1;
                list1 = tmp;
            }
        }

        ListNode* new_head = new ListNode(0);
        new_head->next = list1;
        ListNode* p1 = new_head, * q1 = list1, * q2 = list2;
        while(NULL != q1)
        {
            int val = q1->val + q2->val;
            if(9 < val)
            {
                q1->val = val % 10;
                ++p1->val;

                while(p1->next != q1)
                {
                    p1 = p1->next;
                    p1->val = 0;
                }
                p1 = p1->next;
            }
            else if(9 > val)
            {
                q1->val = val;
                p1 = q1;
            }
            else
            {
                q1->val = val;
            }

            q1 = q1->next, q2 = q2->next;
        }

        if(new_head->val == 0)
        {
            delete new_head;
            return list1;
        }

        return new_head;
    }

    ListNode* multipleTwoList(ListNode* list1, ListNode* list2)
    {
        ListNode* cur = NULL;
        int cnt2 = 0;

        // Calc the length for list2
        ListNode* p1 = list1, * p2 = list2;
        while(NULL != p2)
        {
            p2 = p2->next;
            ++cnt2;
        }

        p2 = list2;
        while(NULL != p2)
        {
            // multiple one by one
            --cnt2;
            if(0 == p2->val) 
            {
                continue;
            }

            p1 = list1;
            ListNode* tmpList = new ListNode(0);
            ListNode* cur_node = tmpList;
            while(NULL != p1)
            {
                int val = p2->val * p1->val;
                if(9 >= val)
                {
                    
                }
            }
        }
    }
};

int main()
{
    vector<int> input1 = {1,2,3};
    vector<int> input2 = {1,8,9,4};
    Solution sol;
    ListNode* result = sol.plusTwoList(createList(input1), createList(input2));
    deleteList(result, true);
    return 0;
}
