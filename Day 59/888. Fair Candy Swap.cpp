// Link:https://leetcode.com/problems/fair-candy-swap/
// Time Complexity: O(NlogN)
// Space Complexity: O(1)

class Solution
{
public
    int binarySearch(int sum1, int sum2, int[] v, int n)
    {
        int lo = 0;
        int hi = n - 1;
        int mid;
        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            int a = sum1 - v[mid];
            int b = sum2 + v[mid];
            if (a == b)
                return mid;
            else if (a > b)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }

public
    int[] fairCandySwap(int[] aliceSizes, int[] bobSizes)
    {
        Arrays.sort(aliceSizes);
        Arrays.sort(bobSizes);
        int n = aliceSizes.length;
        int m = bobSizes.length;
        int aliceSum = 0, bobSum = 0;

        for (int i = 0; i < n; i++)
            aliceSum += aliceSizes[i];
        for (int i = 0; i < m; i++)
            bobSum += bobSizes[i];

        if (n > m)
        {
            for (int i = 0; i < m; i++)
            {
                int j = binarySearch(aliceSum + bobSizes[i], bobSum - bobSizes[i], aliceSizes, n);
                if (j != -1)
                    return new int[]{aliceSizes[j], bobSizes[i]};
            }
        }

        for (int i = 0; i < n; i++)
        {
            int j = binarySearch(bobSum + aliceSizes[i], aliceSum - aliceSizes[i], bobSizes, m);
            if (j != -1)
                return new int[]{aliceSizes[i], bobSizes[j]};
        }

        return new int[]{-1, -1};
