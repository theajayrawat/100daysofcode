// Link:https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    long long trappingWater(int arr[], int n)
    {
        // code here'
        int l = 0;
        int r = n - 1;
        int leftMax = 0;
        int rightMax = 0;
        long long ans = 0;

        while (l < r)
        {
            if (arr[l] < arr[r])
            {
                if (arr[l] > leftMax)
                {
                    leftMax = arr[l];
                }
                else
                {
                    ans += (leftMax - arr[l]);
                }
                l++;
            }
            else
            {
                if (arr[r] > rightMax)
                {
                    rightMax = arr[r];
                }
                else
                {
                    ans += (rightMax - arr[r]);
                }
                r--;
            }
        }

        return ans;
    }
};