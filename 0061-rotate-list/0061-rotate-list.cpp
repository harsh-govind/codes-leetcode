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
    int length(ListNode *head)
    {
        int i=0;
        while(head)
        {
            i++;
            head=head->next;
        }
        return i;
    }
    ListNode *rev(ListNode *head)
    {
        ListNode *p=head, *q=nullptr, *r=nullptr;
        while(p)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        head=q;
        return q;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = length(head);
        if(!head or !head->next or k%n==0)
            return head;
       
        head=rev(head);
        
        ListNode *prev=nullptr, *p=head;
        int i=k%n;
        while(p and i--)
        {
            prev=p;
            p=p->next;
        }
        prev->next=nullptr;
        head=rev(head);
        p=rev(p);
        
        ListNode *q=head;
        while(q->next)
        {
            q=q->next;
        }
        
        q->next=p;
        
            
        return head;
    }
};