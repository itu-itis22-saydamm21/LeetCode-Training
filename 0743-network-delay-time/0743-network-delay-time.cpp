class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector< vector<int> > dist(n + 1, vector<int>(n + 1, INT_MAX));
        
        for(int i = 1; i <= n; i++){
            dist[i][i] = 0;
        }
        
        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];
            dist[u][v] = w;
        }
        
        for(int via = 1; via <= n; via++){
            for(int u = 1; u <= n; u++){
                for(int v = 1; v <= n; v++){
                    if (dist[u][via] != INT_MAX && dist[via][v] != INT_MAX
                       && dist[u][via] + dist[via][v] < dist[u][v]){
                        dist[u][v] = dist[u][via] + dist[via][v];
                    }
                }
            }
        }
        
        int maxDist = 0;
        for(int i = 1; i <= n; i++){
            if(dist[k][i] == INT_MAX) return -1;
            maxDist = max(maxDist, dist[k][i]);
        }
        return maxDist;
    }
};