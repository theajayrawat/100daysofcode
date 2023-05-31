// Webpage:https://leetcode.com/problems/shuffle-an-array/

class Solution {
public:
    vector<int>original;
    vector<int>permute;
    Solution(vector<int>& nums) {
        original=nums;
        permute=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int t1 = rand()%permute.size();
        int t2 = rand()%permute.size();
        swap(permute[t1],permute[t2]);
        return permute;
    }
};