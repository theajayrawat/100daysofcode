// Webapge:https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    int cnt(int n, int x)
    {
        if(n%x!=0 || n/x==0)
            return 0;
        return 1+cnt(n/x,x);
    }

    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i+=5)
        {
            ans+=cnt(i,5);
        }

        return ans;
    }
};