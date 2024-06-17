class Solution {
public:
    void backtracking(vector<int>& candidate, int target, vector<int> curr, vector<vector<int>> &res, int curr_sum, int start){
        if(curr_sum > target) return;
        if(curr_sum == target){
            res.push_back(curr);
            return;
        }
        
        for(int i = start; i < candidate.size(); i++){
            curr.push_back(candidate[i]);
            backtracking(candidate, target, curr, res, curr_sum + candidate[i], i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(candidates, target, curr, res, 0, 0);
        return res;
    }
};