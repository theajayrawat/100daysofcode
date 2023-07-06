// Link:https://www.codingninjas.com/studio/problems/873366?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Time Complexity: O(N)
// Space Complexity: O(1)

#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    // Write your code here
    int xr = 0;

    for (int i = 0; i < n; i++)
    {
        xr ^= arr[i];
        xr ^= (i + 1);
    }

    int bitNo = 0;

    while (1)
    {
        if (xr & (1 << bitNo))
            break;

        bitNo++;
    }

    int zero = 0;
    int ones = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] & (1 << bitNo))
        {
            ones ^= arr[i];
        }
        else
            zero ^= arr[i];

        if ((i + 1) & (1 << bitNo))
        {
            ones ^= (i + 1);
        }
        else
            zero ^= (i + 1);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (zero == arr[i])
            cnt++;
    }

    pair<int, int> p;
    if (cnt == 2)
        p = make_pair(ones, zero);
    else
        p = make_pair(zero, ones);

    return p;
}
