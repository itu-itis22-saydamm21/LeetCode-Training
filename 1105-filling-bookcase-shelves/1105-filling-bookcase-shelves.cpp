class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);  
        dp[n] = 0; 
        
        for (int i = n - 1; i >= 0; --i) {
            int width = 0, height = 0;
            for (int j = i; j < n; ++j) {
                width += books[j][0]; 
                if (width > shelfWidth) break;  
                height = max(height, books[j][1]);  
                dp[i] = min(dp[i], height + dp[j + 1]); 
            }
        }
        
        return dp[0];
    }
};