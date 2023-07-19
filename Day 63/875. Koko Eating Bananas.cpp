// Link:https://www.codingninjas.com/studio/problems/minimum-rate-to-eat-bananas_7449064?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries
// Time Complexity:  O(log(max(arr[]))*N)
// Space Complexity: O(1)

long hoursRequired(vector<int> &v, long k)
{
    long h = 0;
    for (int i : v)
    {
        if (i % k != 0)
        {
            h++;
        }
        h += (i / k);
    }
    return h;
}
int minimumRateToEatBananas(vector<int> v, int h)
{
    // Write Your Code Here
    sort(v.begin(), v.end());
    int n = v.size();
    long start = 1;
    long end = v[n - 1];

    while (start <= end)
    {
        long mid = start + (end - start) / 2;
        long hour = hoursRequired(v, mid);
        if (hour > h)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (int)start;
}