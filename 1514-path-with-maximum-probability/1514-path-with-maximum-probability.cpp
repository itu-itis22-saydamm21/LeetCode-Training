class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<vector<pair<double, int>>> adj(n + 1);

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({succProb[i], edges[i][1]});
            adj[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        vector<double> dist(n + 1, 0.0);
        dist[start_node] = 1.0;

        while(!pq.empty()) {
            double curr_prob = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(dist[u] > curr_prob) continue;

            for(auto& ad : adj[u]) {
                int v = ad.second;
                double w = ad.first; 
                if(dist[u] * w > dist[v]) {
                    dist[v] = dist[u] * w;
                    pq.push({dist[v], v});
                }
            }   
        }

        return dist[end_node];
    }
};
