// Link:https://www.codingninjas.com/studio/problems/bubble-sort_624380?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
//  Time Complexity: O(N^2)
//  Space Complexity: O(1)

void bubbleSort(vector<int> &arr, int n)
{
    // Write Your Code Here
    for (int i = n - 1; i >= 0; i--)
    {
        int didSwap = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
            //Best Case Time Complexity: O(N)
        }
    }
}