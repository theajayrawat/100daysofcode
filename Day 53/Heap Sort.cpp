// Link:https://www.codingninjas.com/studio/problems/heap-sort_1262153?leftPanelTab=0
// Time complexity: O(NlogN)
// Space complexity: O(N)

#include <bits/stdc++.h>
void Heapify(vector<int> &arr, int n, int index)
{

    int right = 2 * index + 2;
    int left = 2 * index + 1;
    int largestNode = index;

    if (left < n && arr[left] > arr[largestNode])
    {
        largestNode = left;
    }

    if (right < n && arr[right] > arr[largestNode])
    {
        largestNode = right;
    }

    if (largestNode != index)
    {
        swap(arr[index], arr[largestNode]);
        Heapify(arr, n, largestNode);
    }
}

vector<int> heapSort(vector<int> &arr, int n)
{
    // Write your code here.
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }

    return arr;
}