#define pii pair<int, int>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        int n =  points.size();
        vector<int> vis(n+1, 0);
        int ans = 0;
        pq.push({0, 0});
        while(!pq.empty()){
            auto node = pq.top(); pq.pop();
            if(vis[node.second])
                continue;
            vis[node.second]++;
            ans+=node.first;
            vector<int> co = points[node.second];

            for(int i=1; i<n; i++){
                if(!vis[i])
                    pq.push({abs(co[0] - points[i][0]) + abs(co[1] - points[i][1]), i} );
            }
        }
        return ans;
    }
};