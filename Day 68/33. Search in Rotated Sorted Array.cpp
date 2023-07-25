// Link:https://leetcode.com/problems/search-in-rotated-sorted-array/
// Time Complexity: O(LogN)
// Space Complexity: O(LogN)

class Solution
{
public
    int solve(int[] nums, int target, int s, int e)
    {
        if (s > e)
        {
            return -1;
        }

        int m = s + (e - s) / 2;
        if (nums[m] == target)
            return m;
        else if (nums[m] >= nums[s])
        {
            if (target >= nums[s] && target <= nums[m])
                return solve(nums, target, s, m - 1);
            else
                return solve(nums, target, m + 1, e);
        }
        else if (target >= nums[m] && target <= nums[e])
            return solve(nums, target, m + 1, e);
        else
            return solve(nums, target, s, m - 1);
    }
public
    int search(int[] nums, int target)
    {
        int s = 0;
        int e = nums.length - 1;
        return solve(nums, target, s, e);
    }
}