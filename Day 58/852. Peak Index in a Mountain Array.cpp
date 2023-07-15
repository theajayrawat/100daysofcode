// Link:https://leetcode.com/problems/peak-index-in-a-mountain-array/
// Time Complexity: O(LogN)
// Space Complexity: O(1)

class Solution
{
public
    int peakIndexInMountainArray(int[] arr)
    {
        int start = 0;
        int end = arr.length - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (mid + 1 < arr.length && arr[mid] > arr[mid + 1])
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }

        return start;
    }
}