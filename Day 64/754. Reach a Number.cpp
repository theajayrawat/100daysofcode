// Link:https://leetcode.com/problems/reach-a-number/
// Time Complexity:  O(LogN)
// Space Complexity: O(1)

class Solution
{
public
    int reachNumber(int target)
    {
        target = Math.abs(target);
        int start = 1, end = target, numOfMoves = 0;
        long finalPosition = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            long sum = (long)mid * (mid + 1) / 2;
            if (sum >= target)
            {
                finalPosition = sum;
                numOfMoves = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ((int)(finalPosition - target)) % 2 == 0 ? numOfMoves : numOfMoves % 2 == 0 ? numOfMoves + 1
                                                                                           : numOfMoves + 2;
    }
}