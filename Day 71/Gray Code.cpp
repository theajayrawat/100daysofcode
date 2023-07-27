// Link:https://practice.geeksforgeeks.org/problems/gray-code-1611215248/1
// Time Complexity: O(2^N)
// Space Complexity: O(2^N)

class Solution
{
    public:
    vector<string> generate(int n){
        if(n==1){
            return {"0","1"};
        }
        
        vector<string>ans;
        vector<string>temp=generate(n-1);
        for(int i=0;i<temp.size();i++){
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back("1"+temp[i]);
        }
        
        return ans;
    }
    vector<string> graycode(int n)
    {
        //code here
        return generate(n);
    }
};