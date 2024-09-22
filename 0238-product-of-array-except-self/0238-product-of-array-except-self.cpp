class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero_cnt = 0;
        int product = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zero_cnt++;
            else
                product *= nums[i];
        }
        if(zero_cnt){
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] != 0 ) nums[i] = 0;
                else{
                    if(zero_cnt > 1) nums[i] = 0;
                    else
                        nums[i] = product;
                }
            }
        }
        else{
            for(int i = 0; i < nums.size(); i++){
                nums[i] = product / nums[i];
            }
        }
        return nums;
    }
};