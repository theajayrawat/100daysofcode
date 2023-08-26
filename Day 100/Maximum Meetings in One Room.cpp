// Link:https://practice.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1
// Time Complexity: O(N*LogN)
// Space Complexity: O(N)

class Solution
{
public:
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
    {
        vector<pair<int, pair<int, int>>> v;

        for (int i = 0; i < N; i++)
        {
            pair<int, int> p = make_pair(S[i], i + 1);
            v.push_back(make_pair(F[i], p));
        }

        sort(v.begin(), v.end());

        int prevF = v[0].first;

        vector<int> ans;
        ans.push_back(v[0].second.second);

        for (int i = 1; i < N; i++)
        {
            if (prevF < v[i].second.first)
            {
                ans.push_back(v[i].second.second);
                prevF = v[i].first;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};