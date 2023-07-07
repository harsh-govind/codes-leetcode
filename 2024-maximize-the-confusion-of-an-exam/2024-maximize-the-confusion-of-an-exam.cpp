class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int n = a.length();
        int t = 0, f = 0, ans = 0;
        int l = 0, r = 0;

        while (r < n) {
            if (a[r] == 'T')
                t++;
            else
                f++;

            while (min(t, f) > k) {
                if (a[l] == 'T')
                    t--;
                else
                    f--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};