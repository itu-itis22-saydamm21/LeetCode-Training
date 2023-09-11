class Solution {
public:
    int dfs(vector<vector<int>>& grid, int h, int w){
        int m = grid[0].size();
        int n = grid.size();
        if(w < 0 || w >= m || h < 0 || h >= n || grid[h][w] == 0)
            return 0;
        
        grid[h][w] = 0;
        int area = 1;
        area += dfs(grid, h - 1, w);
        area += dfs(grid, h + 1, w);
        area += dfs(grid, h, w + 1);
        area += dfs(grid, h, w - 1);
        
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int w = grid[0].size();
        int h = grid.size();
        int maxArea = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == 1){
                    int area = dfs(grid, i, j);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};