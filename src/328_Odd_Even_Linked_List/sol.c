/**********************************
* Example:
* Given 1->2->3->4->5->NULL,
* return 1->3->5->2->4->NULL.
* Note:
* The relative order inside both the even and odd groups should remain as it was in the input.
* The first node is considered odd, the second node even and so on ...
*
* 用两个指针，一个指针p指向当前遍历的奇数节点的最后一个位置，另一个指针q指向待提取的奇数节点的前一个位置。
* 然后把q.next 的节点删除，插入到p.next的位置即可
************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head)
{
	if (NULL == head) 
	{
		return head;
	}

	struct ListNode* p = head;
	struct ListNode* q = head;

	while (NULL != q) 
	{
		q = q->next;
		if (NULL == q || NULL == q->next) 
		{
			break;
		}

		struct ListNode* next_p = p->next;
		struct ListNode* next_q = q->next;
		q->next = next_q->next;
		p->next = next_q;
		next_q->next = next_p;
		p = p->next;
	}
	
	return head;
}
