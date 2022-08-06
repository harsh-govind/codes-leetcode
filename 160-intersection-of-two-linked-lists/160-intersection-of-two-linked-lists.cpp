/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *a, ListNode *b)
        {
            ListNode *p = a, *ans = nullptr;
            while (p)
            {
                p->val = -1 *p->val;
                p = p->next;
            }

            p = b;
            while (p)
            {
                if (p->val < 0)
                {
                    ans = p;
                    break;
                }
                p = p->next;
            }

            p = a;
            while (p)
            {
                p->val = -1 *p->val;
                p = p->next;
            }
            return ans;
        }
};