typedef long long ll;

class Solution
{
    public:
        int shortestSubarray(vector<int> &v, int k)
        {
            int ans = INT_MAX, n = v.size();
            ll sumSoFar = 0;

            map<ll, int> prefSumMap;
            prefSumMap[0] = -1;

            for (int i = 0; i < n; ++i)
            {
                sumSoFar += v[i];
                prefSumMap[sumSoFar] = i;

                auto itUB = prefSumMap.upper_bound(sumSoFar - k);

                if (itUB == prefSumMap.begin()) continue;

                for (auto it = prefSumMap.begin(); it != itUB; ++it)
                {
                    ans = min(ans, (i - it->second));
                }

                prefSumMap.erase(prefSumMap.begin(), itUB);
            }

            return ans == INT_MAX ? -1 : ans;
        }
};