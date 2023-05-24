// Webpage:https://leetcode.com/problems/find-peak-element/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=n-1;

        while(i<=j)
        {
            int mid = (i + j) / 2;
            if( mid+1<n && nums[mid] < nums[mid + 1]) i = mid + 1;
            else j = mid-1;
        }

        return i;
    }
};