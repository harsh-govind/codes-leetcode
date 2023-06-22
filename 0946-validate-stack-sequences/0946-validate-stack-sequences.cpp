class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {
            stack<int> s;
            int j = 0, n = pushed.size();
            for (int i = 0; i < n; i++)
            {
                s.push(pushed[i]);

                while (!s.empty() and s.top() == popped[j])
                {
                    j++;
                    s.pop();
                }
            }

            if (s.empty() and j == n)
            {
                return true;
            }

            return false;
        }
};