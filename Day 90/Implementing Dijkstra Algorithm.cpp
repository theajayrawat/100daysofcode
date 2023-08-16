// Link:https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1
// Time Complexity: O(E*logV)
// Space Complexity: O(V)

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(V, INT_MAX);

        pq.push({0, S});
        ans[S] = 0;

        while (!pq.empty())
        {

            pair<int, int> p = pq.top();
            pq.pop();
            int weight = p.first;
            int node = p.second;

            for (auto it : adj[node])
            {

                int edge = it[0];
                int edgeWeight = it[1];

                if (weight + edgeWeight < ans[edge])
                {

                    ans[edge] = weight + edgeWeight;
                    pq.push({ans[edge], edge});
                }
            }
        }

        return ans;
    }
};