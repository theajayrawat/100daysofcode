// Link:https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/
// Time Complexity: O(N)
// Space Complexity: O(N)


class Solution
{
public:
    string reverseInvert(string s)
    {
        string str = "";

        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                str += '1';
            else
            {
                str += '0';
            }
        }
        return str;
    }
    string solve(int n, int k)
    {
        if (n == 1)
            return "0";

        string a = solve(n - 1, k);
        string b = reverseInvert(a);
        return a + "1" + b;
    }
    char findKthBit(int n, int k)
    {
        string str = solve(n, k);
        return str[k - 1];
    }
};
