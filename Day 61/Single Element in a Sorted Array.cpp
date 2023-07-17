// Link:https://www.codingninjas.com/studio/problems/single-element-in-a-sorted-array_8230826?challengeSlug=striver-sde-challenge
// Time Complexity: O(logN)
// Space Complexity: O(1)

int singleNonDuplicate(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    int lo = 0;
    int hi = n - 1;

    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        bool even = (hi - mid) % 2 == 0;
        if (arr[mid] == arr[mid + 1])
        {
            if (even)
            {
                lo = mid + 2;
            }
            else
            {
                hi = mid - 1;
            }
        }
        else if (arr[mid] == arr[mid - 1])
        {
            if (even)
            {
                hi = mid - 2;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            return arr[mid];
        }
    }
    return arr[lo];
}