// Link:https://practice.geeksforgeeks.org/problems/2d3fc3651507fc0c6bd1fa43861e0d1c43d4b8a1/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long long int count=0;
        long long int ans=0;
        int mini=INT_MAX;
        
        for(int i=0;i<N;i++){
            count+=(long long)(B[i]/2);
            ans+=(long long )A[i]*(B[i]-B[i]%2);
            if(B[i]>=2)
            mini=min(A[i],mini);
        }
      
      if(count%2!=0)ans-=mini*2;
      return ans;
    }
};