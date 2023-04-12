class Solution {
public:
    string simplifyPath(string path) {
        deque<string> s;
        int i = 0;

        while(i<path.size())
        {
            if(path[i] == '/')i++;
            else
            {
                string str = "";
                while(i<path.size() && path[i] != '/')
                {
                    str += path[i];i++;
                }
                if(str == "..")
                {
                    if(!s.empty())s.pop_back();
                }
                else if(str != ".") s.push_back(str);
            }
        }

        string ans = "/";
        while(!s.empty())
        {
            ans += s.front();
            ans += '/';
            s.pop_front();
        }
        if(ans.size()>1)
            ans.pop_back();

        return ans;
    }
};