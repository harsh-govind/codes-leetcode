/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *p = list1, *q = list2;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while (p and q)
        {
            if (p->val < q->val)
            {
                temp->next = new ListNode(p->val);
                temp = temp->next;
                p = p->next;
            }
            else if (q->val < p->val)
            {
                temp->next = new ListNode(q->val);
                temp = temp->next;
                q = q->next;
            }
            else if (p->val == q->val)
            {
                temp->next = new ListNode(p->val);
                temp = temp->next;
                p = p->next;

                temp->next = new ListNode(q->val);
                temp = temp->next;
                q = q->next;
            }
        }
        while (p)
        {
            temp->next = new ListNode(p->val);
            temp = temp->next;
            p = p->next;
        }
        while (q)
        {
            temp->next = new ListNode(q->val);
            temp = temp->next;
            q = q->next;
        }
        ListNode *head = dummy->next;
        return head;
    }
};