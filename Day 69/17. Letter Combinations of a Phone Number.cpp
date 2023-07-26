// Link:https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Time Complexity: O(N * 3^N)
// Space Complexity: O(3^N)

class Solution
{
public
    void solve(String digits, String[] v, int i, List<String> ans, String curr)
    {
        if (digits.length() == i)
        {
            ans.add(curr);
            return;
        }

        int index = digits.charAt(i) - '0';
        String str = v[index];

        for (int j = 0; j < str.length(); j++)
        {
            solve(digits, v, i + 1, ans, curr + str.charAt(j));
        }
    }
public
    List<String> letterCombinations(String digits)
    {
        List<String> ans = new ArrayList<>();
        if (digits.length() == 0)
            return ans;
        String[] v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        String curr = "";
        solve(digits, v, 0, ans, curr);
        return ans;
    }
}