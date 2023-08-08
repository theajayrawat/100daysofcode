// Link:https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        unordered_set<int> set;
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            set.insert(arr[i]);
        }

        for (int i = 0; i < N; i++)
        {
            int count = 1;
            int e = arr[i];
            if (set.find(e - 1) == set.end())
            {
                while (set.find(++e) != set.end())
                {
                    count++;
                }
            }
            ans = max(count, ans);
        }
        return ans;
    }
};