// Link:https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

class Solution
{
public
    int binarySearch(int[] numbers, int target, int n)
    {
        int low = 0;
        int high = n - 1;
        while (low <= high)
        {
            int mid = (high - low) / 2 + low;
            if (numbers[mid] == target)
            {
                while (mid >= 0 && (numbers[mid] == target))
                {
                    mid--;
                }
                return mid + 1;
            }
            else if (numbers[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
public
    int specialArray(int[] nums)
    {
        Arrays.sort(nums);
        int n = nums.length;
        for (int i = 0; i <= 1000; ++i)
        {
            if (n - binarySearch(nums, i, n) == i)
                return i;
        }

        return -1;
    }
}