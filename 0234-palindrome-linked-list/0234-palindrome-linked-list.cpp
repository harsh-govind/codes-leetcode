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
        bool isPalindrome(ListNode *head)
        {
            string s = "";
            ListNode *p = head;

            while (p)
            {
                s += to_string(p->val);
                p = p->next;
            }

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] != s[s.size() - i - 1])
                {
                    return false;
                }
            }
            return true;
        }
};