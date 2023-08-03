// Link:https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
// Time Complexity: O(V+E)
// Space Complexity: O(V)

class Solution {
  public:
    vector<int> topologicalSort(int V, unordered_map<int,vector<pair<int,int>>>&adj) 
	{
	    queue<int>q;
	    vector<int>indegree(V,0);
	    for(int u=0;u<V;u++){
	        for(auto &v:adj[u])indegree[v.first]++;
	    }
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)q.push(i);
	    }
	    
	    vector<int>ans;
	    while(!q.empty()){
	        int u=q.front();
	        ans.push_back(u);
	        q.pop();
	        for(auto &v:adj[u]){
	            indegree[v.first]--;
	            if(indegree[v.first]==0)q.push(v.first);
	        }
	    }
	    return ans;
	}
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            pair<int,int>p=make_pair(v,w);
            adj[u].push_back(p);
        }
        
        vector<int>topoSort=topologicalSort(N,adj);
        
        vector<int>ans(N,INT_MAX);
        ans[0]=0;
        for(int x:topoSort){
            if(ans[x]!=INT_MAX){
                for(auto i:adj[x]){
                    ans[i.first]=min(i.second+ans[x],ans[i.first]);
                }
            }

        }
        
        for(int i=0;i<N;i++){
            if(ans[i]==INT_MAX)ans[i]=-1;
        }
        
        return ans;
    }
};

