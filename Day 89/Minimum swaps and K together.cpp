// Link:https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int minSwap(int arr[], int n, int k)
    {
        // Complet the function
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
                cnt++;
        }

        int badNo = 0;
        int ans = INT_MAX;
        for (int i = 0; i < cnt; i++)
        {
            if (arr[i] > k)
                badNo++;
        }

        ans = min(ans, badNo);

        for (int i = cnt; i < n; i++)
        {
            if (arr[i - cnt] > k)
            {
                badNo--;
            }
            if (arr[i] > k)
                badNo++;

            ans = min(ans, badNo);
        }

        return ans;
    }
};
