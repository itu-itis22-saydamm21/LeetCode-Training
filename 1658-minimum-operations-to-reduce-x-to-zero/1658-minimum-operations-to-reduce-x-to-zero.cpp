class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sub_sum = accumulate(nums.begin(), nums.end(), 0) - x;
        int sub_size = INT_MIN;
        int sum = 0;
        if(sub_sum < 0)
            return -1;
        while(right < n){
           sum += nums[right];
           while(sum > sub_sum){
               sum -= nums[left];
               left++;
           }
            if(sum == sub_sum)
                sub_size = max(sub_size, right - left + 1);
            right++;
        }
        return sub_size == INT_MIN ? -1 : n - sub_size;
    }    
};