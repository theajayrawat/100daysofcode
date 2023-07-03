// Link:https://practice.geeksforgeeks.org/problems/maximum-index3307/1
// Time Complexity: O(N)
// Space Complexity: O(N)

class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int>lMin(n);
        lMin[0]=arr[0];
        for(int i=1;i<n;i++){
            lMin[i]=min(lMin[i-1],arr[i]);
        }
        
        vector<int>rMax(n);
        rMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rMax[i]=max(rMax[i+1],arr[i]);
        }
        
        int i = 0, j = 0;
        int maxDiff = -1;
        while (j < n && i < n) {
            if (lMin[i] <= rMax[j]) {
                maxDiff = max(maxDiff, j - i);
                j = j + 1;
            } else
                i = i + 1;
        }
        
        return maxDiff;
    }

};