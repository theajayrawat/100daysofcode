// Link:https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        // Your code here
        int sum = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i])
                sum += 1;
            else
                sum -= 1;
            count += mp[sum];
            mp[sum]++;
        }

        return count;
    }
};