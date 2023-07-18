// Link:https://www.codingninjas.com/studio/problems/ayush-gives-ninjatest_1097574?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(M* log(end-start))
// Space Complexity: O(1)

#include <bits/stdc++.h>
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    // Write your code here.
    if (m < n)
        return -1;

    long long start = 0;
    long long end = 0;

    for (int i = 0; i < m; i++)
    {
        if (start < time[i])
            start = time[i];
        end += time[i];
    }

    while (start <= end)
    {
        long mid = start + (end - start) / 2;

        long long sum = 0;
        long long piece = 1;
        for (int num : time)
        {
            if (sum + num > mid)
            {
                piece++;
                sum = num;
            }
            else
            {
                sum += num;
            }
        }
        if (piece > n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return start;
}