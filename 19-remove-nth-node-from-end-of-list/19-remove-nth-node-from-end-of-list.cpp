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
    int count(ListNode *p)
    {
        int ans=0;
        while(p)
        {
            ans++;
            p=p->next;
        }
        return ans;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //count - n + 1
        
        int l = count(head);
        if(l==1)
        {
            return nullptr;
        }
        else if(l==2 and n==1)
        {
            head->next=nullptr;
            return head;
        }
        else if(l==n)
        {
            return head->next;
        }
        l = l - n;
        ListNode*p=head, *q=head;
        for(int i=0;i<l;i++)
        {
            q=p;
            p=p->next;            
        }
        cout<<p->val<<" "<<q->val<<endl;
        q->next=p->next;
        p=nullptr;
        
        return head;
    }
};