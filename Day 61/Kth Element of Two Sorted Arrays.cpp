// Link:https://www.codingninjas.com/studio/problems/1112629?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0
// Time Complexity: O(log(min(m,n)))
// Space Complexity: O(1)

#include <bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    // Write your code here.
    if (n < m)
    {
        return ninjaAndLadoos(row2, row1, n, m, k);
    }
    int low = max(0, k - n);
    int high = min(k, m);

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int l1 = (cut1 == 0) ? INT_MIN : row1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : row2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : row1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : row2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 1;
}
