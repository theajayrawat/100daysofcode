// Link:https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	int max_ind=n-1;
    	int min_ind=0;
    	long long m=arr[n-1]+1;
    	
    	
    	for(int i=0;i<n;i++){
    	    if(i%2==0){
    	        arr[i]=(arr[max_ind]%m)*m+arr[i];
    	        max_ind--;
    	    }
    	    else{
    	         arr[i]=(arr[min_ind]%m)*m+arr[i];
    	         min_ind++;
    	    }
    	}
    	
    	for(int i=0;i<n;i++){
    	    arr[i]=arr[i]/m;
    	}
    	 
    }
};

