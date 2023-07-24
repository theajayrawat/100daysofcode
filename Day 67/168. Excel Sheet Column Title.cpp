// Link:https://leetcode.com/problems/excel-sheet-column-title/
// Time Complexity: O(logN)
// Space Complexity: O(1)

class Solution
{
public
    String convertToTitle(int columnNumber)
    {
        StringBuilder ans = new StringBuilder();

        while (columnNumber > 0)
        {
            columnNumber--;

            ans.append((char)((columnNumber) % 26 + 'A'));
            columnNumber = (columnNumber) / 26;
        }

        return ans.reverse().toString();
    }
}