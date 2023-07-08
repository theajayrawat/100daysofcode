// Link:https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1
// Time Complexity:  O(min(n, m)) + O(n*logn) + O(m*logm)
// Space Complexity: O(1)

class Solution
{
public:
    // Function to merge the arrays.
    void merge(long long arr1[], long long arr2[], int n, int m)
    {
        // code here
        int left = n - 1;
        int right = 0;

        while (left >= 0 && right < m)
        {
            if (arr1[left] > arr2[right])
            {
                swap(arr1[left], arr2[right]);
                left--, right++;
            }
            else
            {
                break;
            }
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};