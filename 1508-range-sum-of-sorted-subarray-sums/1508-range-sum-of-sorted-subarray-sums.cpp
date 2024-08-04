class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long> subarray_sums;
        long long MOD = 1000000007;
        for(int i = 0; i < n; i++){
            long long sum = 0;
            for(int j = i; j < n; j++){
                sum += nums[j];
                subarray_sums.push_back(sum);
            }
        }
        sort(subarray_sums.begin(), subarray_sums.end());
        long long res = 0;
        for(int i = left - 1; i <= right - 1; i++){
            res = (res + subarray_sums[i]) % MOD;
        }
        res = res % MOD;
        return res;
    }
};