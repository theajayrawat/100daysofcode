// Link:https://www.codingninjas.com/studio/problems/subset-sum_3843086?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=2
// Time Complexity:  O((2^N)*log(2^N))
// Space Complexity: O(n)

#include <bits/stdc++.h>
void solve(vector<int> &nums, int i, int sum, vector<int> &ans)
{
    if (i == nums.size())
    {
        ans.push_back(sum);
        return;
    }

    solve(nums, i + 1, sum, ans);
    solve(nums, i + 1, sum + nums[i], ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    solve(num, 0, 0, ans);
    sort(ans.begin(), ans.end());
    return ans;
}