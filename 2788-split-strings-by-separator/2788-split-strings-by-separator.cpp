class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> ans;
        for(auto &word:words)
        {
            string current="";
            for(auto &ch:word)
            {
                if(ch==separator)
                {
                    if(current!="")
                        ans.push_back(current);
                    current="";
                }
                else
                {
                    current+=ch;
                }
            }
            if(current.size()>0 and current!="")
            {
                ans.push_back(current);
            }
        }
        return ans;
    }
};