// Link:https://www.codingninjas.com/studio/problems/630450?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(logN)
// Space Complexity: O(1)

int findPivot(int *nums, int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (mid<end && nums[mid] > nums[mid+1])
            return mid;
        else if (mid>start && nums[mid-1] > nums[mid])
        {
            return mid - 1;
        }
        else if(nums[start]>nums[mid]) {
            end=mid-1;
        }
        else{
            start=mid+1;
        } 
    }
    return -1;
}
int binarySearch(int *nums, int start, int end, int target)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int search(int *arr, int n, int key)
{
    // Write your code here.
    int pivot = findPivot(arr, n);
    int ans = binarySearch(arr, 0, pivot, key);
    if (ans == -1)
        ans = binarySearch(arr, pivot + 1, n - 1, key);
    return ans;
}