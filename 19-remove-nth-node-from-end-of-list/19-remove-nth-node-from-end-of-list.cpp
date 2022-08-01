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
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        ListNode *p=head, *q=head;
        int count = 0;
        while(p)
        {
            if(count>n)
            {
                q=q->next;
            }
            p=p->next;
            count++;
        }
        if(count == n)
        {
            return head->next;
        }
        cout<<q->val<<endl;
        q->next=q->next->next;
        return head;
    }
};