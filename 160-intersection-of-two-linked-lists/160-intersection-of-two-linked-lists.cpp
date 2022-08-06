/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        ListNode* getIntersectionNode(ListNode *a, ListNode *b)
        {
            unordered_set<ListNode*> check;

            ListNode *p = a;

            while (p)
            {
                check.insert(p);
                p = p->next;
            }

            p = b;

            while (p)
            {
                if (check.find(p) != check.end())
                {
                    return p;
                }
                p = p->next;
            }
            return nullptr;
        }
};