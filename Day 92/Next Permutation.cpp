// Link:https://practice.geeksforgeeks.org/problems/next-permutation5226/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    vector<int> nextPermutation(int N, vector<int> arr)
    {
        // code here
        int index = N;

        for (int j = N - 1; j > 0; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                index = j - 1;
                break;
            }
        }

        if (index == N)
        {
            sort(arr.begin(), arr.end());
            return arr;
        }

        int val = INT_MAX;
        int i;
        for (int j = N - 1; j > index; j--)
        {
            if (val > arr[j] && arr[j] > arr[index])
            {
                i = j;
                val = arr[j];
            }
        }

        swap(arr[index], arr[i]);

        sort(arr.begin() + index + 1, arr.end());
        return arr;
    }
};