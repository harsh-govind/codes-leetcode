class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0; i<tokens.size(); i++)
        {
            if(s.size()==0 or !(tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="/" or tokens[i]=="*"))
            {
                s.push(stoi(tokens[i]));
            }
            else
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int toPush;
                if(tokens[i]=="+")
                {
                    toPush=b+a;
                }
                else if(tokens[i]=="-")
                {
                    toPush=b-a;
                }
                else if(tokens[i]=="/")
                {
                    toPush=b/a;
                }
                else
                {
                    toPush=b*a;
                }
                s.push(toPush);
            }
        }
    
        return s.top();
    }
};