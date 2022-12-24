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
        ListNode* swapPairs(ListNode *head)
        {
            vector<int> v;
            if (!head)
            {
                return nullptr;
            }
            ListNode *p = head;

            while (p)
            {
                v.push_back(p->val);
                p = p->next;
            }

            for (int i = 0; i < v.size() - 1; i += 2)
            {
                swap(v[i], v[i + 1]);
            }

            p = head;
            int i = 0;
            while (p and i < v.size())
            {
                p->val = v[i++];
                p = p->next;
            }

            return head;
        }
};