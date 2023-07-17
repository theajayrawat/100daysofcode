// Link:https://www.codingninjas.com/studio/problems/1062679?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(logN)
// Space Complexity: O(1)

int NthRoot(int n, int m)
{
    // Write your code here.
    int i = 1;
    int j = m;

    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (pow(mid, n) == m)
        {
            return mid;
        }
        else if (pow(mid, n) > m)
            j = mid - 1;
        else
            i = mid + 1;
    }

    return -1;
}
