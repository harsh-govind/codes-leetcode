/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* q) {
        if(q==nullptr)
            return q;
        ListNode *x = q, *y = q, *z = nullptr;
            if (q)
            {
                z = q->next;
            }
            while (z)
            {
                x = y;
                y = z;
                z = z->next;
                y->next = x;
            }
            q->next = nullptr;
            q = y;
            return q;
    }
};