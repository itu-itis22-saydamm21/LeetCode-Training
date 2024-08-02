class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int ones = count(nums.begin(), nums.end(), 1);
        if (ones == 0 || ones == n) return 0;
        
        vector<int> double_arr(nums.begin(), nums.end());
        double_arr.insert(double_arr.end(), nums.begin(), nums.end());
        
        int swaps = n, zeros = 0;
        for(int i = 0; i < ones; i++){
            if(double_arr[i] == 0) zeros++;
        }
        swaps = zeros;
        
        for(int i = ones; i < double_arr.size(); i++){
            if(double_arr[i] == 0) zeros++;
            if(double_arr[i - ones] == 0) zeros--;
            swaps = min(swaps, zeros);
        }
        return swaps;
    }
};