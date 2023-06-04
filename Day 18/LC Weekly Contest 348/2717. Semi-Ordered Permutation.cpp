// Webpage:https://leetcode.com/problems/semi-ordered-permutation/

class Solution {
public:
    void displaceToLast(vector<int>& nums, int i, int n, int &cnt){
        for(int j=i;j<n-1;j++){
            nums[j]=nums[j+1];
            cnt++;
        }
        nums[n-1]=n; 
    }
    
    void displaceToFirst(vector<int>& nums, int i, int n, int &cnt){
        for(int j=i;j>0;j--){
            nums[j]=nums[j-1];
            cnt++;
        }
        nums[0]=1;
    }
    
    int semiOrderedPermutation(vector<int>& nums) {
        int n=nums.size();
        if(nums[n-1]==n && nums[0]==1)
            return 0;
        
        int cnt=0;
        if(nums[n-1]!=n){
            for(int i=0;i<n;i++){
                if(nums[i]==n){
                    displaceToLast(nums,i,n,cnt);
                    break;
                }
                    
            }
        }
        if(nums[0]!=1){
            for(int i=0;i<n;i++){
                if(nums[i]==1){
                    displaceToFirst(nums,i,n,cnt);
                    break;
                }
                
            }
        }
        return cnt;
    }
};