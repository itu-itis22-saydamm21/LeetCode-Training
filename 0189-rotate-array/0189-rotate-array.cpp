class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k >= n) k = k % n;
        vector<int> tmp(n);
        int r = n - k;
        int l = 0;
        int curr = 0;
        for(; r < n; r++){
            tmp[curr++] = nums[r];
        }
        for(; curr < n; curr++){
            tmp[curr] = nums[l++];
        }
        for(int i = 0; i < n; i++){
            nums[i] = tmp[i];
        }
    }
};