class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});
        effort[0][0] = 0;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!pq.empty()){
            int curr_effort = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for(int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];
                if(newx >= 0 && newx < rows && newy >= 0 && newy < cols){
                    int newEffort = max(abs(heights[x][y] - heights[newx][newy]), effort[x][y]);
                    
                    if(newEffort < effort[newx][newy]){
                        effort[newx][newy] = newEffort;
                        pq.push({newEffort, {newx, newy}});
                    }
                }
            }
        }
        return effort[rows - 1][cols - 1];
    }
};