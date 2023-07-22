// Link:https://www.codingninjas.com/studio/problems/search-pattern-kmp-algorithm_8416386?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
// Time Complexity: O(N+M)
// Sapce Complexity: O(N+M)

vector<int> kmp(string text, int n)
{
    vector<int> prefix(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = prefix[i - 1];

        while (j > 0 && text[i] != text[j])
        {
            j = prefix[j - 1];
        }
        if (text[i] == text[j])
        {
            j++;
        }
        prefix[i] = j;
    }

    return prefix;
}
vector<int> stringMatch(string text, string pattern)
{
    // Write your code here.
    int n = pattern.size();
    int m = text.size();

    if (n > m)
        return {0};

    if (n == m)
    {
        if (text == pattern)
            return {1};
        else
            return {0};
    }

    vector<int> prefix = kmp(pattern, n);

    int i = 0, j = 0;

    vector<int> v;
    while (i < m)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = prefix[j - 1];
            else
                i++;
        }
        if (j == n)
            v.push_back(i - n + 1);
    }

    return v;
}
