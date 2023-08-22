// Link:https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
// Time Complexity: O(V+E)
// Space Complexity: O(E)

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
    {
        // code here
        unordered_map<int, vector<int>> adj;
        for (auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> pq;
        vector<int> ans(N, INT_MAX);

        vector<int> vis(N, 0);
        vis[src] = 1;

        pq.push(src);
        ans[src] = 0;

        while (!pq.empty())
        {
            int node = pq.front();
            pq.pop();

            for (auto it : adj[node])
            {

                if (!vis[it] && ans[node] + 1 < ans[it])
                {

                    ans[it] = ans[node] + 1;
                    pq.push(it);
                    vis[it] = 1;
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }

        return ans;
    }
};