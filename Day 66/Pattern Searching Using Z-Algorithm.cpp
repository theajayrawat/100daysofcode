// Link:https://www.codingninjas.com/studio/problems/pattern-searching-using-z-algorithm_8395752?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
// Time Complexity: O(N+M)
// Sapce Complexity: O(N+M)

void getZarr(string str, vector<int> &Z, int n)
{
    int L, R, k;

    // [L,R] make a window which matches with prefix of s
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;

            if (Z[k] < R - i + 1)
                Z[i] = Z[k];

            else
            {

                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}
vector<int> search(string s, string pattern)
{
    // Write Your Code Here
    string concat = pattern + "$" + s;
    int l = concat.length();

    vector<int> Z(l, 0);
    getZarr(concat, Z, l);

    vector<int> ans;
    int n = pattern.length();
    for (int i = 0; i < l; ++i)
    {
        if (Z[i] == n)
            ans.push_back(i - n);
    }

    return ans;
}
