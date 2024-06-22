class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< vector<pair<int,int>> > adj(n + 1);
        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        
        pq.push({0, k}); // {distance, starting_node}
        dist[k] = 0;
        
        while(!pq.empty()){
            int currentDist = pq.top().first; // To sort by distance 
            int u = pq.top().second;
            pq.pop();
            
            if(dist[u] < currentDist) continue;
            
            for(auto adj : adj[u]){
                int v = adj.first;
                int w = adj.second;
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int maxDist = 0;
        for(int i = 1; i <= n ; i++){
            if(dist[i] == INT_MAX) return -1;
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};