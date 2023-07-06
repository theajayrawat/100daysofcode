// Link:https://www.codingninjas.com/studio/problems/1115652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N)
// Space Complexity: O(N)

#include <bits/stdc++.h>
int subarraysXor(vector<int> &arr, int x)
{

    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
        int y = xr ^ x;

        cnt += mpp[y];
        mpp[xr]++;
    }
    return cnt;
}
