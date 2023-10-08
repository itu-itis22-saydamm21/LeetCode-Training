class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        
        vector<vector<int>> dp(size1, vector<int>(size2));
        dp[0][0] = nums1[0] * nums2[0];
        for(int i = 1; i < size1; i++)
            dp[i][0] = max(dp[i-1][0], nums1[i] * nums2[0]);
        
        for(int i = 1; i < size2; i++)
            dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
        
        for(int i = 1; i < size1; i++){
            for(int j = 1; j < size2; j++)
                dp[i][j] = max(nums1[i] * nums2[j], max(dp[i - 1][j - 1] + nums1[i] * nums2[j], max(dp[i - 1][j], dp[i][j - 1])));
        }
        return dp[size1 - 1][size2 - 1];
    }
};