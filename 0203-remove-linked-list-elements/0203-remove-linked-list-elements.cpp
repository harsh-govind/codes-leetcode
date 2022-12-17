/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeElements(ListNode *head, int val)
        {
            ListNode *p = head, *prev = head;

            while (p)
            {
                if (p->val == val)
                {
                    if (p == head)
                    {
                        head = head->next;
                        p = p->next;
                    }
                    else
                    {
                        prev->next = p->next;
                        p = p->next;
                    }
                }
                else
                {
                    prev = p;
                    p = p->next;
                }
            }
            return head;
        }
};