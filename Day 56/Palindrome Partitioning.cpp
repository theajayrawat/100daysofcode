// Link:https://www.codingninjas.com/studio/problems/palindrome-partitioning_626181?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
// Time Complexity: O(k * 2^n)     "k" is average length of every subsequence
// Space Complexity: O(2^n * k)

#include <bits/stdc++.h>
bool isPalindrome(string s, int i, int j)
{

    while (i <= j)
    {
        if (s[i++] != s[j--])
            return false;
    }

    return true;
}
void dfs(vector<vector<string>> &ans, vector<string> &str, string s, int i)
{
    if (i == s.size())
    {
        ans.push_back(str);
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        if (isPalindrome(s, i, j))
        {
            str.push_back(s.substr(i, j - i + 1));
            dfs(ans, str, s, j + 1);
            str.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s)
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> str;
    dfs(ans, str, s, 0);
    return ans;
}