// Link:https://www.codingninjas.com/studio/problems/minimise-max-distance_7541449?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
// Time Complexity: O(N*LogA) "A" max diffrence
// Space Complexity: O(1)

#include <bits/stdc++.h>
int numberOfGasStationsRequired(long double dist, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numberInBetween = (arr[i] - arr[i - 1]) / dist;
        if ((arr[i] - arr[i - 1]) / dist == numberInBetween * dist)
            numberInBetween--;
        cnt += numberInBetween;
    }

    return cnt;
}
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    long double low = 0;
    long double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)arr[i + 1] - arr[i]);
    }

    while (high - low > 1e-6)
    {
        long double mid = low + (high - low) / 2;
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k)
            low = mid;
        else
            high = mid;
    }

    return high;
}