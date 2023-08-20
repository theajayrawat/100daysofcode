// Link:https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
        if (m > n)
            return false;

        int j = 0;
        for (int i = 0; i < n && j < m; i++)
        {
            if (str1[i] == str2[j])
            {
                j++;
            }
            else
            {

                char ch = char((str1[i] - 'a' + 1) % 26 + 97);
                if (ch == str2[j])
                {
                    j++;
                }
            }
        }

        return (j == m);
    }
};