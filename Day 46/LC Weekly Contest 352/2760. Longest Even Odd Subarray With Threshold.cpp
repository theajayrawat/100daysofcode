// Link:https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/
// Time Complexity: O(N)
// Space Complexity: O(1)

class Solution
{
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int cnt = 0;
            if (nums[i] % 2 || nums[i] > threshold)
                continue;
            else
                cnt = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j - 1] % 2 == nums[j] % 2 || nums[j] > threshold)
                    break;
                else
                    cnt++;
            }
            ans = max(ans, cnt);
            i=j-1;
        }

        return ans;
    }
};