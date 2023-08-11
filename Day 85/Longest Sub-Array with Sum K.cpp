// Link:https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1
// Time Complexity: O(N)
// Space Complexity: O(N)

        unordered_map<int,int>mp;
         int sum=0;
         int ans=0;
	    for(int i=0;i<N;i++){
	        sum+=A[i];
	        if(sum-K==0){
	            ans=i+1;
	        }
	        else if(mp.find(sum-K)!=mp.end()){
	           ans=max(ans,i-mp[sum-K]);
	        }
	        if(mp.find(sum)==mp.end()){
	            mp[sum]=i;
	        }
	    }
	    return ans;