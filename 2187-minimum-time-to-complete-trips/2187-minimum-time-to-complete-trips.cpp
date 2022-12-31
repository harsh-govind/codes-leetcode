class Solution
{
    public:
        bool solve(vector<int> &time, int totalTrips, long long mid)
        {
            long long int cnt = 0;

            for (int i = 0; i < time.size(); i++)
            {
                cnt += mid / time[i];

                if (cnt >= totalTrips) return true;
            }

            return false;
        }
    long long minimumTime(vector<int> &time, int totalTrips)
    {

        long long ans = 1e14;
        long long low = 0;
        long long high = 1e14;
        long long mid;

        while (low <= high)
        {

            mid = low + (high - low) / 2;

            if (solve(time, totalTrips, mid))
            {

                ans = mid;
                high = mid - 1;
            }
            else
            {

                low = mid + 1;
            }
        }

        return ans;
    }
};