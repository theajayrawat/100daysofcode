// Link:https://practice.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
// Time Complexity:  O(4*N*M )
// Space Complexity:  O(N*M )

class Solution
{
public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here
        if (X == 0 && Y == 0)
            return 0;

        queue<pair<int, pair<int, int>>> q;
        int n = A.size();
        int m = A[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({0, {0, 0}});

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            if (r == X && c == Y)
                return dis;

            for (int i = 0; i < 4; i++)
            {
                int newr = r + dr[i];
                int newc = c + dc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m && A[newr][newc] == 1 && vis[newr][newc] == 0)
                {

                    vis[newr][newc] = 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        // If no path is found from source to destination.
        return -1;
    }
};