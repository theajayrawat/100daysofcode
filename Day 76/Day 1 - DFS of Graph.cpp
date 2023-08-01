// Link:https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    void solve(vector<int> adj[], int u, vector<int> &ans, vector<int> &vis)
    {
        ans.push_back(u);
        vis[u] = 1;

        for (auto &v : adj[u])
        {
            if (!vis[v])
                solve(adj, v, ans, vis);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                solve(adj, i, ans, vis);
            }
        }
        return ans;
    }
};