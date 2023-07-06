// Link:https://www.codingninjas.com/studio/problems/1112652?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Time Complexity: O(N*logN)
// Space Complexity: O(N)

#include <bits/stdc++.h>
int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int j = mid + 1;
    int i = low;
    for (i = low; i <= mid; i++)
    {
        while (j <= high && arr[i] > 2 * arr[j])
        {
            j++;
        }
        cnt += (j - (mid + 1));
    }

    vector<int> v;
    i = low;
    j = mid + 1;
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
int mergeSort(vector<int> &arr, int low, int high)
{

    int count = 0;
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        count += mergeSort(arr, low, mid);
        count += mergeSort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);
    }

    return count;
}
int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    return mergeSort(arr, 0, n - 1);
}