// Link:https://leetcode.com/problems/subsets-ii/
// Time Complexity: O(N * 2^N)
// Space Complexity: O(N * 2^N)

class Solution
{
public
    List<List<Integer>> subsetsWithDup(int[] nums)
    {
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        ans.add(new ArrayList<>());
        int start = 0;
        int end = 0;
        for (int i = 0; i < nums.length; i++)
        {
            start = 0;
            if (i > 0 && nums[i] == nums[i - 1])
                start = end;
            end = ans.size();
            for (int j = start; j < end; j++)
            {
                List<Integer> temp = new ArrayList<>(ans.get(j));
                temp.add(nums[i]);
                ans.add(temp);
            }
        }
        return ans;
    }
}