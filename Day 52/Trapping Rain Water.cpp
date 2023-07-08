// Link:https://www.codingninjas.com/studio/problems/trapping-rain-water_630519?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0
// Time Complexity: O(N)
// Space Complexity: O(1)

long long getTrappedWater(long long *arr, int n)
{
    // Write your code here.
    int left = 0;
    int right = n - 1;
    long long leftMax = 0;
    long long rightMax = 0;
    long long ans = 0;

    while (left <= right)
    {
        if (arr[left] < arr[right])
        {
            if (arr[left] > leftMax)
            {
                leftMax = arr[left];
            }
            else
            {
                ans += (leftMax - arr[left]);
            }
            left++;
        }
        else
        {
            if (arr[right] > rightMax)
            {
                rightMax = arr[right];
            }
            else
            {
                ans += (rightMax - arr[right]);
            }
            right--;
        }
    }

    return ans;
}