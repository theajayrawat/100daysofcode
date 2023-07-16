// Link:https://leetcode.com/problems/find-the-duplicate-number/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

class Solution
{
public
    int findDuplicate(int[] nums)
    {
        int low = 1;
        int high = nums.length - 1;
        while (low <= high)
        {
            int count = 0;
            int mid = low + (high - low) / 2;
            for (int num : nums)
            {
                if (num <= mid)
                    count++;
            }
            if (count <= mid)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
}
