// Link:https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        // Your code here

        int left = 1, right = 1;

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            while (sum > s)
            {
                sum -= arr[left - 1];
                left++;
            }
            if (sum == s && left <= i + 1)
            {
                right = i + 1;
                return {left, right};
            }
        }

        return {-1};
    }
};