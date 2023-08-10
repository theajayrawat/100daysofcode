// Link:https://practice.geeksforgeeks.org/problems/maximum-index3307/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
public:
    int maxIndexDiff(int arr[], int n)
    {
        // code here
        vector<int> v_min(n);
        v_min[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            v_min[i] = min(v_min[i - 1], arr[i]);
        }

        vector<int> v_max(n);
        v_max[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++)
        {
            v_max[n - i - 1] = max(v_max[n - i], arr[n - i - 1]);
        }

        int ans = 0, i = 0, j = 0;
        while (i < n && j < n)
        {
            if (v_min[i] <= v_max[j])
            {
                ans = max(ans, j - i);
                j++;
            }
            else
                i++;
        }

        return ans;
    }
};