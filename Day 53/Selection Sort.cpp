// Link:https://www.codingninjas.com/studio/problems/selection-sort_624469?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
//  Time Complexity: O(N^2)
//  Space Complexity: O(1)

void selectionSort(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int index = -1;
        for (int j = i; j < n; j++)
        {
            if (mini > arr[j])
            {
                mini = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}