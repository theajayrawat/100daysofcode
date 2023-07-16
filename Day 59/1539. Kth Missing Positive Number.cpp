// Link:https://leetcode.com/problems/kth-missing-positive-number/
// Time Complexity: O(logN)
// Space Complexity: O(1)

class Solution
{
public
    int findKthPositive(int[] arr, int k)
    {
        int n = arr.length;
        int start = 0, end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] - (mid + 1) < k)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start + k;
    }
}