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
        ListNode *reverse(ListNode *q)
        {
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
    
        ListNode *mid(ListNode *head)
        {
            ListNode *p = head, *q = head, *r=head;;
            while (p)
            {
                p = p->next;
                if (p)
                {
                    r=q;
                    p = p->next;
                    q = q->next;
                }
            }
            r->next=nullptr;
            return q;
        }
    
        void print(ListNode *p)
        {
            while(p)
            {
                cout<<p->val<< " ";
                p=p->next;
            }
            cout<<endl;
        }
        
        void reorderList(ListNode *head)
        {
            ListNode *p = head, *q=mid(head), *ans=head;
            print(p);
            print(q);
            q=reverse(q);
            ListNode *t1, *t2;
            while (p and q)
            {
                t1 = p;
                p = p->next;
                t2 = q;
                q = q->next;
                t1->next = t2;
                t2->next = p;
            }
            if (q)
            {
                t2->next = q;
            } 
            cout<<endl;
            print(p);
            print(q);
            
        }
};