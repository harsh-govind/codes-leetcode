/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* insertionSortList(ListNode *head)
        {
            ListNode *dummy = new ListNode(-1);

            ListNode *p = head;

            while (p)
            {
                ListNode *temp = p->next;

                ListNode *q = dummy->next, *prev = nullptr;

                while (q and q->val < p->val)
                {
                    prev = q;
                    q = q->next;
                }

                if (prev == nullptr)
                {
                    ListNode *temp = dummy->next;
                    dummy->next = p;
                    dummy->next->next = temp;
                }
                else
                {
                    ListNode *temp = prev->next;
                    prev->next = p;
                    prev->next->next = temp;
                }

                p = temp;
            }

            return dummy->next;
        }
};