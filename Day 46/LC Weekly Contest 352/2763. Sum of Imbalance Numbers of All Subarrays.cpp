// Link:https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/
// Time Complexity: O(N^2)
// Space Complexity: O(N)

class Solution
{
public:
    int sumImbalanceNumbers(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;
            int imbalanceCount = 0;
            for (int j = i; j < n; j++)
            {
                if (!st.count(nums[j]))
                {
                    if (st.count(nums[j] - 1) && st.count(nums[j] + 1))
                        imbalanceCount--;
                    else if ((!st.empty()) && (!st.count(nums[j] - 1)) && (!st.count(nums[j] + 1)))
                        imbalanceCount++;
                }
                st.insert(nums[j]);
                count += imbalanceCount;
            }
        }
        return count;
    }
};