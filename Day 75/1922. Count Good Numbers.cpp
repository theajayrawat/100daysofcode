// Link:https://leetcode.com/problems/count-good-numbers/
// Time Complexity: O(logN)
// Space Complexity: O(logN)

class Solution {
public:
    long long m=1e9+7;
    int myPow(long long x, long long n) {
        if(n==0)return 1;
        int l= myPow(x,n/2);
        if(n%2==0)return ((l%m)*(l%m))%m;
        else return ((l%m)*(l%m)*(x%m))%m;
    }
    int countGoodNumbers(long long n) {
        long long odd=n/2;
        long long even=n/2+n%2;
        return ((myPow(4,odd)%m)*(myPow(5,even)%m))%m;

    }
};
