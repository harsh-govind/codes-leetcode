class Solution
{
    public:
        bool wordPattern(string pattern, string s)
        {
            vector<string> words;
            string ss = "";
            for (int i = 0; i < s.size(); i++)
            {

                if (s[i] == ' '
                    or i == s.size() - 1)
                {
                    if (i == s.size() - 1)
                    {
                        ss += s[i];
                    }
                    words.push_back(ss);

                    ss = "";
                }
                else
                {
                    ss += s[i];
                }
            }
            if (words.size() != pattern.size())
            {
               	// cout << "\nfirst\n";
                return false;
            }
            unordered_map<char, string> mp;
            unordered_set<string> st;
           	// for (auto &val: words)
           	// {
           	//     cout << val << " ";
           	// }
            string chk = words[0];
            bool wordsflag = true;
            for (int i = 1; i < words.size(); i++)
            {
                if (words[i] != chk)
                {
                    wordsflag = false;
                    break;
                }
            }

            char chk2 = pattern[0];
            bool patternflag = true;
            for (int i = 1; i < pattern.size(); i++)
            {
                if (pattern[i] != chk2)
                {
                    patternflag = false;
                    break;
                }
            }

            if ((patternflag and!wordsflag) or(!patternflag and wordsflag))
            {
                cout<<"this";
                return false;
            }

            for (int i = 0; i < pattern.size(); i++)
            {
                if (mp.find(pattern[i]) == mp.end())
                {
                    if(st.find(words[i])!=st.end())
                    {
                        return false;
                    }
                    mp[pattern[i]] = words[i];
                    st.insert(words[i]);
                }
                else
                {
                    if (mp[pattern[i]] != words[i])
                    {
                       	// cout << "\nsecond\n";
                       	// cout << pattern[i] << " " << words[i] << "\n";
                        return false;
                    }
                }
               	// cout << pattern[i] << " " << words[i] << "\n";
            }

            return true;
        }
};