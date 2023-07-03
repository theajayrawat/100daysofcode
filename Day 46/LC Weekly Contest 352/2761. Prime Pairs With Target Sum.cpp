// Link:https://leetcode.com/problems/prime-pairs-with-target-sum/
// Time Complexity: O(N*log(log N))
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> solve(int n)
    {
        vector<int> is_prime(n + 1, true);
        is_prime[0] = false;
        is_prime[1] = false;
        for (int p = 2; p * p <= n; p++)
        {
            if (is_prime[p])
            {
                for (int i = p * p; i <= n; i += p)
                {
                    is_prime[i] = false;
                }
            }
        }

        vector<int> ans;
        for (int i = 2; i <= n; i++)
        {
            if (is_prime[i])
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
    vector<vector<int>> findPrimePairs(int n)
    {
        vector<vector<int>> ans;
        vector<int> v = solve(n);
        unordered_map<int, int> mp;
        for (int i = 0; i < v.size(); i++)
        {
            mp[v[i]]++;
        }

        for (int i = 2; i <= n / 2; i++)
        {
            int y = n - i;
            if (mp.find(i) != mp.end() && mp.find(y) != mp.end())
                ans.push_back({i, y});
        }

        return ans;
    }
};