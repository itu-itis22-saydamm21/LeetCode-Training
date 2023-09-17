class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int target = (1 << n) - 1;
        
        queue<pair<int, int>>   q;
        vector<vector<int>> visited(n, vector<int>(1 << n, false));
        
        for(int i = 0; i < n; i++){
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 0; i < size; i++){
                auto [node, state] = q.front();
                q.pop();
                
                if(state == target)
                    return steps;
                
                for(int neighbor : graph[node]){
                    int nextState = state | (1 << neighbor);
                    
                    if(!visited[neighbor][nextState]){
                        q.push({neighbor, nextState});
                        visited[neighbor][nextState] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};