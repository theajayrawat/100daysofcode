// Link:https://leetcode.com/problems/first-missing-positive/
// Time Complexity:  O(N)
// Space Complexity: O(1)

class Solution
{
public
    int firstMissingPositive(int[] nums)
    {
        int i = 0;
        int n = nums.length;
        while (i < n)
        {
            int index = nums[i] - 1;
            if (index < 0 || index >= n)
                i++;
            else if (nums[i] != i + 1 && nums[i] != nums[index])
            {
                int temp = nums[i];
                nums[i] = nums[index];
                nums[index] = temp;
            }
            else
            {
                i++;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
}