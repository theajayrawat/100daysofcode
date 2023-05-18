// Website:https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=-1;
        int start=0;
        int end=nums.size()-1;
        while(start <= end){
            int mid = start + (end -start)/2;
            if(nums[mid] == target){
                a=mid;
                end = mid -1;
            }else if(nums[mid] > target){
                end = mid -1;
            }else if(nums[mid]<target){
                start = mid + 1;
            }
        }

        int b=-1;
        start=0;
        end=nums.size()-1;
        while(start <= end){
            int mid = start + (end -start)/2;
            if(nums[mid] == target){
                b=mid;
                start=mid+1;
            }else if(nums[mid] > target){
                end = mid -1;
            }else if(nums[mid]<target){
                start = mid + 1;
            }
        }
        
        vector<int>ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;

    }
};