// Link:https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Time Complexity: O(V+E)
// Space Complexity: O(V)


class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dfs(adj, i, visited, inRecursion))
                return true;
        }
        return false;
    }
    bool dfs(vector<int> adj[], int u, vector<bool> &visited, vector<bool> &inRecursion)
    {
        visited[u] = true;
        inRecursion[u] = true;
        for (int &v : adj[u])
        {
            if (!visited[v] && dfs(adj, v, visited, inRecursion))
                return true;
            else if (inRecursion[v])
                return true;
        }
        inRecursion[u] = false;
        return false;
    }
};

