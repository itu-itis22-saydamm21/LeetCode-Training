class Solution {
private:
    vector< vector<int> > adj;
    vector< vector<int> > result;
    vector<int> low;
    vector<int> tin;
    vector<bool> visited;
    int timer = 0;
public:
    void    dfs(int node, int p = -1){
        visited[node] = true;
        tin[node] = low[node] = timer++;
        for(int child : adj[node]){
            if(child == p) continue;
            if(visited[child]){
                low[node] = min(low[node], low[child]);
            }
            else{
                dfs(child, node);
                low[node] = min(low[node], low[child]);
                if(low[child] > tin[node]){
                    if(child < node) result.push_back({child, node});
                    else result.push_back({node, child});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        adj.resize(n);
        for(int i = 0; i < connections.size(); i++){
            int u, v;
            u = connections[i][0];
            v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        low.resize(n);
        tin.resize(n);
        visited.resize(n, false);
        for(int i = 0; i < n ; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        return result;
    }
        
};