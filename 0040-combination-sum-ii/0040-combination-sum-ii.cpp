class Solution {
public:
    map<vector<int>, int> mp;
    void backtracking(vector<int>& candidate, int target, vector<int> curr, vector<vector<int>> &res, int curr_sum, int start){
        if(curr_sum > target) return;
        if(curr_sum == target && !mp[curr]){
            res.push_back(curr);
            mp[curr]++;
            return;
        }
        
        for(int i = start; i < candidate.size(); i++){
            if(i > start && candidate[i] == candidate[i - 1])
                continue;
            curr.push_back(candidate[i]);
            backtracking(candidate, target, curr, res, curr_sum + candidate[i], i + 1);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(candidates, target, curr, res, 0, 0);
        return res;
    }
};