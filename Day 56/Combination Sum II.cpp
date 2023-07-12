// Link:https://www.codingninjas.com/studio/problems/1112622?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Time Complexity: O(k * 2^n)     "k" is average length of every subset
// Space Complexity: O(2^n * k)

#include <bits/stdc++.h>
void help(vector<vector<int>> &v, vector<int> &arr, vector<int> &temp, int i, int target)
{
    if (target == 0)
    {
        v.push_back(temp);
        return;
    }
    else if (target < 0)
    {
        return;
    }

    for (int j = i; j < arr.size(); j++)
    {
        if (i != j && arr[j] == arr[j - 1])
            continue;
        temp.push_back(arr[j]);
        help(v, arr, temp, j + 1, target - arr[j]);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<vector<int>> v;
    vector<int> temp;
    sort(arr.begin(), arr.end());
    help(v, arr, temp, 0, target);
    return v;
}
