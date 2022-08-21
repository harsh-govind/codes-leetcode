class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> se;
        
        for(int i=0; i<s.size(); i++)
        {
            if(se.find(s[i])==se.end())
            {
                se.insert(s[i]);
            }
            else
            {
                return s[i];
            }
        }
        
        return '0';
    }
};