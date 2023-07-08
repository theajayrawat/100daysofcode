// Link:https://www.codingninjas.com/studio/problems/799352?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(N^2)
// Space Complexity: O(1)

class Solution
{
public:
    // Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    {
        // Your code here
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            while (i > 0 && arr[i] == arr[i - 1])
                i++;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = arr[i] + arr[k] + arr[j];
                if (sum == 0)
                    return true;
                else if (sum < 0)
                    j++;
                else
                    k--;
            }
        }

        return false;
    }
};