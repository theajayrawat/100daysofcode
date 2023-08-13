// Link:https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
// Time Complexity: O(N*log(N))
// Space Complexity: O(N)

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (ans.size() && a[i] <= ans[ans.size() - 1])
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
            else
            {
                ans.push_back(a[i]);
            }
        }

        return ans.size();
    }
};