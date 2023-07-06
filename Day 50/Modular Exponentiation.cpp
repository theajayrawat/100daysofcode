// Link:https://www.codingninjas.com/studio/problems/1082146?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
// Time Complexity: O(logN)
// Space Complexity: O(logN))

#include <bits/stdc++.h>
int modularExponentiation(int x, int n, int m)
{
    // Write your code here.
    if (n == 0)
        return 1;
    if (n < 0)
    {
        n = abs(n);
        x = 1 / x;
    }

    long long l = modularExponentiation(x, n / 2, m) % m;
    long res = (l * l) % m;
    if (n % 2 == 0)
        return res;
    return (res * x) % m;
}