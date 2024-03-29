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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *p=head, *q=head, *r=head;
        
        if(head->next==nullptr)
        {
            delete head;
            return nullptr;
        }
        
        while(p)
        {
            p=p->next;
            if(p)
            {
                r=q;
                p=p->next;
                q=q->next;
            }
        }        
        r->next=q->next;
        delete q;
        return head;
    }
};