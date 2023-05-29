// Webpage:https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    bool bfs(unordered_map<int,vector<int>>adj,vector<int>indegree,int n, vector<int>&ans){
        queue<int>q;

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
    
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        return ans.size()==n;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(auto &vec: prerequisites)
        {
            int u=vec[0];
            int v=vec[1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        vector<int>ans;
        if(bfs(adj,indegree,numCourses,ans))
            return ans;

        return {};
    }
};