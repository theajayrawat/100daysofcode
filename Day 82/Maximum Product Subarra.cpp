// Link:https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        // code here
        long long maxi = INT_MIN;
        long long pre = 1;
        long long suf = 1;
        for (int i = 0; i < n; i++)
        {
            if (pre == 0)
            {
                pre = 1;
            }
            if (suf == 0)
            {
                suf = 1;
            }
            pre *= arr[i];
            suf *= arr[n - i - 1];
            maxi = max(maxi, max(pre, suf));
        }
        return maxi;
    }
};
