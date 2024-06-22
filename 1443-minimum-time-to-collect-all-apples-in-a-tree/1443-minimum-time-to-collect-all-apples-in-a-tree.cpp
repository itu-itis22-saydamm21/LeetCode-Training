class Solution {
public:
    vector<vector<int>> adj;
    int dfs(vector<bool>& hasApple,int node,int parent){
        int time = 0;
        for(auto adjNode : adj[node]){
            if(adjNode==parent) 
                continue;
            int time_from_child = dfs(hasApple,adjNode,node);
            if(time_from_child > 0 || hasApple[adjNode]) time += (2 + time_from_child);
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for(auto uv : edges){
            int u = uv[0];
            int v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(hasApple, 0, -1);
    }
};