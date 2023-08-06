// Link:https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// Time Complexity: O(NLogN)
// Space Complexity: O(1)

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], int low, int mid, int high)
    {
        vector<long long> temp; // temporary array
        int left = low;         // starting index of left half of arr
        int right = mid + 1;    // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner//
        long long ans = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                ans += (mid - left + 1);
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return ans;
    }

    long long solve(long long arr[], int low, int high)
    {
        if (low >= high)
            return 0;
        long long ans = 0;
        int mid = (low + high) / 2;
        ans += solve(arr, low, mid);       // left half
        ans += solve(arr, mid + 1, high);  // right half
        ans += merge(arr, low, mid, high); // merging sorted halves
        return ans;
    }

    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return solve(arr, 0, N - 1);
    }
};