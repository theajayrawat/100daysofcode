// Link:https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1
// Time Complexity: O(N*N!)
// Space Complexity: O(N^2)

class Solution{
    public:
    //Complete this function
    void solve(string& S, vector<string>&v, int index){
        if(index==S.size()){
            v.push_back(S);
            return;
        }
        
        for(int i=index;i<S.size();i++){
            swap(S[i],S[index]);
            solve(S,v,index+1);
            swap(S[i],S[index]);
        }
    }
    vector<string> permutation(string S)
    {
        //Your code here
        vector<string>v;
        solve(S,v,0);
        
        sort(v.begin(),v.end());
        
        return v;
    }
};f