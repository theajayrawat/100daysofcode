// Link:https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
// Time Complexity: O((K^2)*Log(K))
// Space Complexity: O(K^2)

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> merge(vector<int> a, vector<int> b)
    {
        vector<int> temp;
        int left = 0;
        int right = 0;

        while (left < a.size() && right < b.size())
        {
            if (a[left] <= b[right])
            {
                temp.push_back(a[left]);
                left++;
            }
            else
            {
                temp.push_back(b[right]);
                right++;
            }
        }

        while (left < a.size())
        {
            temp.push_back(a[left]);
            left++;
        }

        while (right < b.size())
        {
            temp.push_back(b[right]);
            right++;
        }

        return temp;
    }

    vector<int> mergeSort(vector<vector<int>> &arr, int low, int high)
    {
        if (low == high)
            return arr[low];
        int mid = (low + high) / 2;
        vector<int> a = mergeSort(arr, low, mid);
        vector<int> b = mergeSort(arr, mid + 1, high);
        return merge(a, b);
    }

    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // code here
        return mergeSort(arr, 0, K - 1);
    }
};