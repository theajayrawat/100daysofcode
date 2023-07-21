// Link:https://leetcode.com/problems/find-right-interval/
// Time Complexity:   O(N^2)
// Space Complexity: O(1)

class Solution
{
public
    int check(int[][] intervals, int i, int n)
    {
        int j = i;
        int k = i - 1;
        int val = intervals[i][1];
        int ans = -1;
        int mini = Integer.MAX_VALUE;
        while (j < n && k >= 0)
        {
            if (mini > intervals[j][0] && intervals[j][0] >= val)
            {
                ans = j;
                mini = intervals[j][0];
            }
            else if (mini > intervals[k][0] && intervals[k][0] >= val)
            {
                ans = k;
                mini = intervals[k][0];
            }
            j++;
            k--;
        }

        while (j < n)
        {
            if (mini > intervals[j][0] && intervals[j][0] >= val)
            {
                ans = j;
                mini = intervals[j][0];
            }
            j++;
        }

        while (k >= 0)
        {
            if (mini > intervals[k][0] && intervals[k][0] >= val)
            {
                ans = k;
                mini = intervals[k][0];
            }
            k--;
        }

        return ans;
    }
public
    int[] findRightInterval(int[][] intervals)
    {
        int n = intervals.length;
        int ans[] = new int[n];
        for (int i = 0; i < n; i++)
        {
            ans[i] = check(intervals, i, n);
        }

        return ans;
    }
}
