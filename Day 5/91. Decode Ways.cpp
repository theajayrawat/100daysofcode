// Webpage:https://leetcode.com/problems/decode-ways/

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return s.empty() ? 0: numDecodings(0,s,dp);    
    }
    int numDecodings(int p, string& s,vector<int> &dp) {
        if(p == s.size()) 
            return dp[p]= 1;
        if(s[p] == '0') 
            return dp[p]=0; 
        if(dp[p]!=-1)
            return dp[p];

        dp[p] = numDecodings(p+1,s,dp);
        if( p+1 < s.size() && (s[p]=='1'|| (s[p]=='2'&& s[p+1]<'7'))) 
            dp[p] += numDecodings(p+2,s,dp);
        return dp[p];
    }
};