/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode*> a;
        ListNode *p=head;
        
        while(p)
        {
            if(a.find(p)==a.end())
            {
                a.insert(p);
            }
            else
            {
                return p;
            }
            p=p->next;
        }
        return nullptr;
    }
};