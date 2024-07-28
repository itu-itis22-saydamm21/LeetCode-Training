class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph(n + 1);
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> dist1(n + 1, INT_MAX);
        vector<int> dist2(n + 1, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 1});
        dist1[1] = 0;
        
        while(!pq.empty()){
            auto [curr_time, u] = pq.top();
            pq.pop();
            for(auto v : graph[u]){
                int next_time = curr_time + time;
                int wait_time = (curr_time / change) % 2 == 1 ? change - (curr_time % change) : 0; 
                next_time += wait_time;
                
                if(next_time < dist1[v]){
                    swap(next_time, dist1[v]);
                    pq.push({dist1[v], v});
                }
                
                if(next_time > dist1[v] && next_time < dist2[v]){
                    dist2[v] = next_time;
                    pq.push({dist2[v], v});
                }
            }
        }
        return dist2[n];
    }
    
};