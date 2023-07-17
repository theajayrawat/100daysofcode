// Link:https://www.codingninjas.com/studio/problems/630450?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(MlogN)
// Space Complexity: O(1)

#include <bits/stdc++.h>
int countSmallerThanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}
int median(vector<vector<int>> &matrix, int m, int n)
{
    // Write your code here.
    int low = 1;
    int high = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += countSmallerThanMid(matrix[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
