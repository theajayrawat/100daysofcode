// Link:https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Time Complexity: O(V+E)
// Space Complexity: O(V)

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool dfs(vector<int> adj[], int u, int parent, vector<bool> &vis)
    {
        vis[u] = true;

        for (auto &v : adj[u])
        {
            if (parent == v)
                continue;
            if (vis[v])
                return true;
            else if (dfs(adj, v, u, vis))
                return true;
        }

        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i] && dfs(adj, i, -1, vis))
                return true;
        }

        return false;
    }
};