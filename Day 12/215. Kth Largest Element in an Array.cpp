// Webpage:https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int>> gq;

        for(int i=0;i<nums.size();i++)
        {
            if(gq.size()==k){
                if(gq.top()<nums[i])
                {
                    gq.pop();
                    gq.push(nums[i]);
                }
            }
            else 
                gq.push(nums[i]);
        }

        return gq.top();
    }
};