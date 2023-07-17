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
        ListNode* rev(ListNode *head)
        {
            ListNode *p = head, *q = nullptr, *r = nullptr;
            while (p)
            {
                r = q;
                q = p;
                p = p->next;
                q->next = r;
            }
            return q;
        }
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *p = rev(l1);
        ListNode *q = rev(l2);
        ListNode *ans = new ListNode(-1);
        ListNode *tail = ans;
        int carry = 0;

        while (p and q)
        {
            int sum = p->val + q->val + carry;

            int value = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(value);
            tail = tail->next;

            p = p->next;
            q = q->next;
        }

        while (p)
        {
            int sum = p->val + carry;

            int value = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(value);
            tail = tail->next;

            p = p->next;
        }

        while (q)
        {
            int sum = q->val + carry;

            int value = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(value);
            tail = tail->next;

            q = q->next;
        }

        while (carry > 0)
        {
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;
        }

        ans->next = rev(ans->next);
        return ans->next;
    }
};