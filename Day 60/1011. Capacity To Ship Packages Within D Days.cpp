// Link:https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public
    int shipWithinDays(int[] weights, int days)
    {
        int start = 0;
        int end = 0;
        int n = weights.length;

        for (int i = 0; i < n; i++)
        {
            start = Math.max(start, weights[i]);
            end += weights[i];
        }

        while (start < end)
        {
            int mid = start + (end - start) / 2;

            int sum = 0;
            int piece = 1;
            for (int num : weights)
            {
                if (sum + num > mid)
                {
                    piece++;
                    sum = num;
                }
                else
                {
                    sum += num;
                }
            }
            if (piece > days)
                start = mid + 1;
            else
                end = mid;
        }
        return end;
    }
}