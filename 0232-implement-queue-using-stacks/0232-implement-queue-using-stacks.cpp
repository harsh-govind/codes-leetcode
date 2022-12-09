class MyQueue
{
    public:
        stack<int> q;
    MyQueue() {}

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        stack<int> dummy;
        while (!q.empty())
        {
            int x = q.top();

            q.pop();

            dummy.push(x);
        }
        int ans;
        if (!dummy.empty())
        {
            ans = dummy.top();
            dummy.pop();
        }

        while (!dummy.empty())
        {
            int x = dummy.top();

            dummy.pop();

            q.push(x);
        }
        return ans;
    }

    int peek()
    {
        stack<int> dummy;
        while (!q.empty())
        {
            int x = q.top();

            q.pop();

            dummy.push(x);
        }
        int ans;
        if (!dummy.empty())
        {
            ans = dummy.top();
        }

        while (!dummy.empty())
        {
            int x = dummy.top();

            dummy.pop();

            q.push(x);
        }
        return ans;
    }

    bool empty()
    {
        return (q.empty());
    }
};

/**
 *Your MyQueue object will be instantiated and called as such:
 *MyQueue* obj = new MyQueue();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->peek();
 *bool param_4 = obj->empty();
 */