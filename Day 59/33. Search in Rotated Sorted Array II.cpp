// Link:https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

class Solution
{
public
    int findPivot(int[] nums)
    {
        int n = nums.length;
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (mid < end && nums[mid] > nums[mid + 1])
                return mid;
            else if (mid > start && nums[mid] < nums[mid - 1])
            {
                return mid - 1;
            }
            else if (nums[start] == nums[mid] && nums[mid] == nums[end])
            {
                if (start + 1 < n && nums[start] > nums[start + 1])
                    return start;
                else if (end > 0 && nums[end] < nums[end - 1])
                    return end - 1;

                start++;
                end--;
            }
            else if (nums[mid] > nums[start] || (nums[start] == nums[mid] && nums[mid] > nums[end]))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return 0;
    }
public
    int binarySearch(int[] nums, int start, int end, int target)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
public
    int search(int[] nums, int target)
    {
        int pivot = findPivot(nums);
        int ans = binarySearch(nums, 0, pivot, target);
        if (ans == -1)
            ans = binarySearch(nums, pivot + 1, nums.length - 1, target);
        return ans;
    }
}