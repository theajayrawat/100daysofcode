// Link:https://practice.geeksforgeeks.org/problems/number-of-occurrence2259/1
// Time Complexity: O(LogN)
// Space Complexity: O(1)

class Solution
{
public:
    /* if x is present in arr[] then returns the count
        of occurrences of x, otherwise returns 0. */
    int count(int arr[], int n, int x)
    {
        // code here
        int i = 0;
        int j = n - 1;

        while (i <= j)
        {
            int mid = i + (j - i) / 2;
            if (arr[mid] == x)
            {
                int k = mid - 1;
                int cnt = 0;

                while (mid < n && arr[mid] == x)
                {
                    cnt++;
                    mid++;
                }

                while (k >= 0 && arr[k] == x)
                {
                    k--;
                    cnt++;
                }

                return cnt;
            }
            else if (arr[mid] > x)
            {
                j = mid - 1;
            }
            else
                i = mid + 1;
        }

        return 0;
    }
};