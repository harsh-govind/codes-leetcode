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
    ListNode* mergeTwoLists(ListNode *a, ListNode *b)
    {
        if(!a)
        {
            return b;
        }
        if(!b)
        {
            return a;
        }
        ListNode *last=nullptr, *ans=nullptr;
        
        if(a and b and a->val < b->val)
        {
            last = a;
            ans = last;
            a = a->next;
            last->next = nullptr;
        }
        else if(a and b and a->val > b->val)
        {
            last = b;
            ans = last;
            b = b->next;
            last->next = nullptr;
        }
        else if(a and b)
        {
            last = a;
            ans = last;
            a = a->next;
            last->next = b;
            last = last->next;
            b=b->next;
            last->next = nullptr;
        }
        
        ListNode *p=a, *q=b;
        
        while(p and q)
        {
            if(p->val < q->val)
            {
                last->next=p;
                p=p->next;
                last=last->next;
                last->next=nullptr;
            }
            else if(p->val > q->val)
            {
                last->next=q;
                q=q->next;
                last=last->next;
                last->next = nullptr;
            }
            else
            {
                ListNode *t1 = p, *t2 = q;
                p = p->next;
                q = q->next;
                last->next = t1;
                t1->next = t2;
                last = t2;
                last->next = nullptr;
            }
        }
        
        if(p)
        {
            last->next = p;
        }
        if(q)
        {
            last->next = q;
        }        
        return ans;
    }
};