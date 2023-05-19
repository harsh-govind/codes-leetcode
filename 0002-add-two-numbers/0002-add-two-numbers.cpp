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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans=nullptr, *k=nullptr, *p=l1, *q=l2;
        int carry=0;
        while(p and q)
        {
            int temp = p->val + q->val + carry;
            int sum = temp%10;
            carry=temp/10;
            if(!k)
            {
                k=new ListNode(sum);
                ans=k;
            }
            else
            {
                ListNode *temp2 = new ListNode(sum);
                k->next=temp2;
                k=k->next;
            }
            p=p->next;
            q=q->next;
        }
        while(p)
        {
            int temp = p->val + carry;
            int sum = temp%10;
            carry=temp/10;
            if(!k)
            {
                k=new ListNode(sum);
                ans=k;
            }
            else
            {
                ListNode *temp2 = new ListNode(sum);
                k->next=temp2;
                k=k->next;
            }
            p=p->next;
        }
        while(q)
        {
            int temp = q->val + carry;
            int sum = temp%10;
            carry=temp/10;
            if(!k)
            {
                k=new ListNode(sum);
                ans=k;
            }
            else
            {
                ListNode *temp2 = new ListNode(sum);
                k->next=temp2;
                k=k->next;
            }
            q=q->next;
        }
        if(carry !=0)
        {
            ListNode *temp2=new ListNode(carry);
            k->next=temp2;
        }
        return ans;
    }
};