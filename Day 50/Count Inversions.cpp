// Link:https://www.codingninjas.com/studio/problems/count-inversions_615?leftPanelTab=0
// Time Complexity: O(N*logN)
// Space Complexity: O(N)

#include <bits/stdc++.h>
long long merge(long long *arr, int low, int mid, int high)
{
    vector<long long> v;
    int i = low;
    int j = mid + 1;
    long long cnt = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            v.push_back(arr[i]);
            i++;
        }
        else
        {
            v.push_back(arr[j]);
            j++;
            cnt += (mid - i + 1);
        }
    }

    while (i <= mid)
    {
        v.push_back(arr[i]);
        i++;
    }

    while (j <= high)
    {
        v.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = v[i - low];
    }

    return cnt;
}
long long mergeSort(long long *arr, int low, int high)
{

    long long count = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }

    return count;
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}
