// Website:https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int index=0;
        int i=0;
        int j=n-1;

        while(i<j)
        {
            int mid=i+(j-i)/2;
            if(mid+1<n && nums[mid]>nums[mid+1])
            {
                index=mid+1;
                break;
            }   
            else if(nums[mid]<=nums[mid+1])
            {
                if(nums[mid]>nums[0])
                    i++;
                else j--;
            }
        }

        if(nums[0]>target || index==0)
        {
            int i=index;
            int j=n-1;

            while(i<=j)
            {
                int mid=i+(j-i)/2;
                if(nums[mid]==target)
                    return mid;
                else if(nums[mid]>target)
                    j--;
                else 
                    i++;
            }   
        }
        else
        {
            int i=0;
            int j=index-1;

            while(i<=j)
            {
                int mid=i+(j-i)/2;
                if(nums[mid]==target)
                    return mid;
                else if(nums[mid]>target)
                    j--;
                else 
                    i++;
            }
        }

        return -1;
    }
};