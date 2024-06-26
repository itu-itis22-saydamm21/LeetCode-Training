class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
        
        for(auto edge : edges){
            int u = edge[0] + 1;
            int v = edge[1] + 1;
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int i = 1; i <= n; i++){
            dist[i][i] = 0; 
        }
        for(int via = 1; via <= n; via++){
            for(int u = 1; u <= n; u++){
                for(int v = 1; v <= n; v++){
                    if (dist[u][via] != INT_MAX && dist[via][v] != INT_MAX
                       && dist[u][via] + dist[via][v] < dist[u][v]){
                        dist[u][v] = dist[u][via] + dist[via][v];
                        dist[v][u] = dist[u][via] + dist[via][v];
                    }
                }
            }
        }
        int cnt;
        int res = -1;
        int min_city = INT_MAX;
        int last = -1;
        for(int i = 1; i <= n; i++){
            cnt = 0;
            for(int j = 1; j <= n; j++){
                if(i == j) continue;
                if(dist[i][j] != INT_MAX && dist[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt <= min_city){
                last = max(last, i) - 1;
                min_city = cnt;
            }
        }
        return last;
    }
};