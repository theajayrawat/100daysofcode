// Link:https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// Time Complexity: O(V + E)
// Space Complexity: O(V)

class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> ans;
        vector<int> check(V, 0);
        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for (auto v : adj[u])
            {
                if (!check[v])
                {
                    q.push(v);
                    check[v] = 1;
                }
            }
        }

        return ans;
    }
};