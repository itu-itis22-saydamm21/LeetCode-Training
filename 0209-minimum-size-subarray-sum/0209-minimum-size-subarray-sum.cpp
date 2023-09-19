class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int i = 0, j = 0;
        int min_cnt = INT_MAX;
        while(i < nums.size()){
            sum += nums[i];
            if(sum >= target){
                while(sum >= target && j <= i){
                    min_cnt = min(min_cnt, i - j + 1);
                    sum -= nums[j];
                    j++;
                }
            }
            i++;
        }
        return min_cnt == INT_MAX ? 0 : min_cnt;
    }
};