// Webpage:https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,  vector<int>&inRecursion,  vector<int>&visited, int u)
    {
        visited[u]=true;
        inRecursion[u]=true;

        for(auto &v:adj[u])
        {
            if(!visited[v]&&dfs(adj,inRecursion,visited,v))
                return true;
            else if(inRecursion[v])
                return true;
        }
        
        inRecursion[u]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>visited(numCourses,false);
        vector<int>inRecursion(numCourses,false);

        for(auto &vec: prerequisites)
        {
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]&&dfs(adj,inRecursion,visited,i))
                return false;
        }

        return true;
    }
};