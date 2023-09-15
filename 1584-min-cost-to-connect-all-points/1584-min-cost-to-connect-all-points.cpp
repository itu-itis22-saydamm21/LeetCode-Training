class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        unordered_map<int, vector<pair<int,int>>> adj;
        int n = points.size();
        for(int i = 0; i < n ; i++){
            for(int j = i + 1; j < n ; j++){
                int delta_x = abs(points[i][0] - points[j][0]); 
                int delta_y = abs(points[i][1] - points[j][1]);
                int cost = delta_x + delta_y;
                adj[j].push_back({cost, i});
                adj[i].push_back({cost, j});
            }
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(n, false);
        pq.push({0, 0});
        int sum = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node])
                continue;
            visited[node] = true;
            sum += cost;
            for(auto a : adj[node]){
                if(!visited[a.second])
                    pq.push(a);
            }
        }
        return sum;
    }
};