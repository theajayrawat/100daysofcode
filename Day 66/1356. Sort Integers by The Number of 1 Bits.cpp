// Link:hhttps://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
// Time Complexity: O(1)
// Sapce Complexity: O(1)

class Solution
{
public
    int cnt_bit(int n)
    {
        int cnt = 0;
        while (n != 0)
        {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
public
    int[] sortByBits(int[] arr)
    {
        int n = arr.length, res[] = new int[n];
        for (int i = 0; i < n; i++)
        {
            res[i] = cnt_bit(arr[i]) * 10001 + arr[i];
        }

        Arrays.sort(res);
        for (int i = 0; i < n; i++)
        {
            res[i] %= 10001;
        }

        return res;
    }
}
