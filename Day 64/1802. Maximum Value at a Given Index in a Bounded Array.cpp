// Link:https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
// Time Complexity:  O(Log(maxSum))
// Space Complexity: O(1)

class Solution
{
public
    long getSumElements(long count, long val)
    {

        return val * count - (count * (count + 1)) / 2;
    }
public
    int maxValue(int n, int index, int maxSum)
    {
        long left = 1;
        long right = maxSum;

        long mid_val;
        long result = 0;

        while (left <= right)
        {

            mid_val = left + (right - left) / 2;

            long left_count = Math.min((long)index, mid_val - 1);

            long left_sum = getSumElements(left_count, mid_val);

            left_sum += Math.max((long)0, index - mid_val + 1);

            long right_count = Math.min((long)n - index - 1, mid_val - 1);

            long right_sum = getSumElements(right_count, mid_val);

            right_sum += Math.max((long)0, n - index - 1 - mid_val + 1);

            if (left_sum + right_sum + mid_val <= maxSum)
            {
                result = Math.max((long)result, mid_val);

                left = mid_val + 1;
            }
            else
            {
                right = mid_val - 1;
            }
        }

        return (int)result;
    }
}