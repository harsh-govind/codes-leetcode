/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *a, ListNode *b)
        {
            if (!a or!b)
            {
                return nullptr;
            }

            ListNode *p = a, *q = b;

            while (p != q)
            {
                p = p == nullptr ? b : p->next;
                q = q == nullptr ? a : q->next;
            }
            return p;
        }
};

/*
//space
class Solution {
public:
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> s;
        ListNode *p =headA;
        while(p)
        {
            s.insert(p);
            p=p->next;
        }

        p=headB;
        while(p)
        {
            if(s.find(p)!=s.end())
            {
                return p;
            }
            s.insert(p);
            p=p->next;
        }

        return nullptr;
    }
};
*/