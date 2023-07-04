// Link:https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        if (k <= 1)
            return 0;

        int ans = 0;
        long long pro = 1;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            pro *= a[right];

            while (pro >= k)
            {
                pro /= a[left];
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};