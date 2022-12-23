/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteDuplicates(ListNode *head)
        {
            unordered_set<int> ss;

            ListNode *p = head, *prev = head;

            while (p)
            {
                if (ss.find(p->val) != ss.end())
                {
                    prev->next = p->next;
                    p = p->next;
                    continue;
                }
                else
                {
                    ss.insert(p->val);
                    prev = p;
                    p = p->next;
                }
            }
            return head;
        }
};