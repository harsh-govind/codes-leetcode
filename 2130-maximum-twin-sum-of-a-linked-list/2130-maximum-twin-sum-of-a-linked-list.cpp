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
        int pairSum(ListNode *head)
        {
            vector<int> a;

            ListNode *p = head;

            while (p)
            {
                a.push_back(p->val);
                p = p->next;
            }

            int ans = INT_MIN;

            for (int i = 0; i < a.size(); i++)
            {
                ans = max(ans, a[i] + a[a.size() - i - 1]);
            }

            return ans;
        }
};