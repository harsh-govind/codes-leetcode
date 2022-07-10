/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        bool hasCycle(ListNode *head)
        {
            ListNode *p = head, *q = head;
            while (q)
            {
                q = q->next;
                if (q)
                {
                    q = q->next;
                    p = p->next;
                }
                if (q == p)
                {
                    return true;
                }
            }
            return false;
        }
};