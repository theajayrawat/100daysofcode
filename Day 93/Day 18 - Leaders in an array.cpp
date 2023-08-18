// Link:https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution
{
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int a[], int n)
    {
        // Code here
        vector<int> v;
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            if (maxi <= a[i])
            {
                v.push_back(a[i]);
                maxi = a[i];
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};