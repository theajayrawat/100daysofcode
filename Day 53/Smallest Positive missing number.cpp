// Link:https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1
//  Time Complexity: O(N)
//  Space Complexity: O(1)

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        // Your code here
        for (int i = 0; i < n; i++)
        {
            while (arr[i] > 0 && arr[i] < n && arr[i] != arr[arr[i] - 1])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};