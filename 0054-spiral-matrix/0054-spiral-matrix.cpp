class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0, right = m - 1, top = 0, bottom = n - 1;
        vector<int> res;
        int cnt = 0;
        while(left <= right && top <= bottom){
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
                cnt++;
            }
            top++;
            if (cnt == n * m) break;
            
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
                cnt++;
            }
            right--;
            if (cnt == n * m) break;
        
            for(int i = right; i >= left; i--){
                res.push_back(matrix[bottom][i]);
                cnt++;
            }
            bottom--;
            if (cnt == n * m) break;
            
            for(int i = bottom; i >= top; i--){
                res.push_back(matrix[i][left]);
                cnt++;
            }
            left++;
            if (cnt == n * m) break;
        }
        return res;
    }
};