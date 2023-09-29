class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1)
            return true;
        bool monotic = true;
        int state = -1;
        for(int i = 0; i + 1 < nums.size(); i++){
            if(nums[i] < nums[i + 1] && state == -1)
                state = 1;
            else if(nums[i] > nums[i + 1] && state == -1)
                state = 0;
  
            if(nums[i] < nums[i + 1] && state != 1)
                return false;
            if(nums[i] > nums[i + 1] && state != 0)
                return false;
        }
        return true;
    }
};