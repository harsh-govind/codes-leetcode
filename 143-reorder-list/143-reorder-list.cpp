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
        void reorderList(ListNode *head)
        {
            ListNode *p = head;
            vector<int> k, k2;
            while (p)
            {
                k.push_back(p->val);
                p = p->next;
            }
 
            for (int i = 0; i < k.size()/2; i++)
            {
                k2.push_back(k[i]);
                k2.push_back(k[k.size()-i-1]);
            }
            p=head;
            int i=0;
            
            if(k.size()%2!=0)
            {
                k2.push_back(k[k.size()/2]);
            }
            
            while(p)
            {
                p->val=k2[i++];
                p=p->next;
            }

        }
};