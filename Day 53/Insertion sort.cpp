// Link:https://www.codingninjas.com/studio/problems/insertion-sort_624381?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
//  Time Complexity: O(N^2)
//  Space Complexity: O(1)

void insertionSort(vector<int> &arr, int size)
{
    // Write your code here.
    for (int i = 0; i < size; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            //Best Case Time Complexity: O(N)
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}