// Link:https://leetcode.com/problems/find-in-mountain-array/
// Time Complexity: O(LogN)
// Space Complexity: O(1)

/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */

class Solution
{
public
    int peakIndexInMountainArray(MountainArray mountainArr)
    {
        int n = mountainArr.length();
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (mid + 1 < n && mountainArr.get(mid) > mountainArr.get(mid + 1))
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
public
    int binarySearch(MountainArray mountainArr, int start, int end, int target, int i)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mountainArr.get(mid) == target)
                return mid;
            if (i == 0)
            {
                if (mountainArr.get(mid) > target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            else
            {
                if (mountainArr.get(mid) < target)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }

        return -1;
    }
public
    int findInMountainArray(int target, MountainArray mountainArr)
    {
        int index = peakIndexInMountainArray(mountainArr);
        int ans = binarySearch(mountainArr, 0, index, target, 0);
        if (ans == -1)
            ans = binarySearch(mountainArr, index, mountainArr.length() - 1, target, 1);

        return ans;
    }
}