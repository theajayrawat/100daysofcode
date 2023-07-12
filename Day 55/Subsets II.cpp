// Link:https://www.codingninjas.com/studio/problems/unique-subsets_3625236?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(k * 2^n)     "k" is average length of every subset 
// Space Complexity: O(2^n * k) 

#include <bits/stdc++.h>
void solve(vector<int> &arr, int n, int i, vector<int> &v, vector<vector<int>> &ans)
{
    ans.push_back(v);

    for (int j = i; j < n; j++)
    {
        if (i != j && arr[j] == arr[j - 1])
            continue;
        v.push_back(arr[j]);
        solve(arr, n, j + 1, v, ans);
        v.pop_back();
    }
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> v;
    vector<int> temp;
    int sum = 0;
    help(v, arr, temp, 0, k, sum);
    return v;
}