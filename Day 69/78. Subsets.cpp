// Link:https://leetcode.com/problems/subsets/
// Time Complexity: O(N * 2^N)
// Space Complexity: O(N * 2^N)

class Solution
{
public
    List<List<Integer>> subsets(int[] nums)
    {
        List<List<Integer>> ans = new ArrayList<>();
        ans.add(new ArrayList<>());
        for (int num : nums)
        {
            int n = ans.size();
            for (int i = 0; i < n; i++)
            {
                List<Integer> temp = new ArrayList<>(ans.get(i));
                temp.add(num);
                ans.add(temp);
            }
        }
        return ans;
    }
}