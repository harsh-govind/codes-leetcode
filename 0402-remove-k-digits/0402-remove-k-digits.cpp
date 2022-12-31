class Solution {
public:
    string removeKdigits(string num, int k) {
        string cur = "";
        for (int i = 0; i < num.size(); ++i){
            if (cur.empty() && num[i] == '0') continue;
            if (k == 0) cur += num[i];
            else{
                while (k > 0 && cur.size() > 0 && cur.back() > num[i]){
                    --k;
                    cur.pop_back();
                }
                if (cur.empty() && num[i] == '0') continue;
                cur += num[i];
            }
        }
        while (k-- > 0 && cur.size() > 0) cur.pop_back();
        if (cur.size() == 0) return "0";
        return cur;
    }
};