// Website:https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
    void combinations(vector<string>&ans, int n, string str,int open, int close)
    {
        if(str.size()==2*n)
        {
            ans.push_back(str);
            return;
        }
        
        if(open<n)
            combinations(ans,n,str+"(",open+1,close);
        if(close<open)
            combinations(ans,n,str+")",open,close+1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        combinations(ans,n,"",0,0);
        return ans;
    }
};