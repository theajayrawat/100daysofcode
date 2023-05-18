// Webpage:https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=INT_MIN;
        int i=0;
        int j=height.size()-1;

        while(i<=j)
        {
            int area=min(height[i],height[j])*(j-i);
            ans=max(ans,area);

            if(height[i]>height[j])
                j--;
            else i++;
        }

        return ans;
    }
};