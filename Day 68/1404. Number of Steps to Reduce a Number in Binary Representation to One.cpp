// Link:https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public
    int numSteps(String s)
    {
        int countSteps = 0;
        int carry = 0;
        for (int i = s.length() - 1; i >= 1; i--)
        {
            int rightMostBit = s.charAt(i) - '0';
            if ((rightMostBit + carry) == 1)
            {
                carry = 1;
                countSteps += 2;
            }
            else
            {
                countSteps++;
            }
        }
        return countSteps + carry;
    }
}