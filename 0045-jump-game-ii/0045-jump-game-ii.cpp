class Solution {
public:
    int jump(vector<int>& nums) {
        int curr_end = 0;
        int max_reach = 0;
        int steps = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            max_reach = max(max_reach, i + nums[i]);
            
            if(i == curr_end){
                steps++;
                curr_end = max_reach;
                //if(curr_end >= nums.size() - 1) break;
            }
        }
        return steps;
    }
};