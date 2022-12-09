class Solution
{
    public:
        void PrintStack(stack<char> s)
        {
           	// If stack is empty then return
            if (s.empty())
                return;

            char x = s.top();

           	// Pop the top element of the stack
            s.pop();

           	// Recursively call the function PrintStack
            PrintStack(s);

           	// Print the stack element starting
           	// from the bottom
            cout << x << " ";

           	// Push the same element onto the stack
           	// to preserve the order
            s.push(x);
        }
    bool backspaceCompare(string s, string t)
    {
        stack<char> a;
        for (int i = 0; i < s.size(); i++)
        {
            if (!a.empty() and s[i] == '#')
            {
                a.pop();
            }
            else if (s[i] != '#')
            {
                a.push(s[i]);
            }
        }

        stack<char> b;
        for (int i = 0; i < t.size(); i++)
        {
            if (!b.empty() and t[i] == '#')
            {
                b.pop();
            }
            else if (t[i] != '#')
            {
                b.push(t[i]);
            }
        }
        PrintStack(a);
        cout << endl;
        PrintStack(b);

        return a == b;
    }
};