#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
using namespace std;

class Solution {
public:
    vector<bool> used;
    void backtracking(vector<int> &nums, vector<int> curr, vector<vector<int> >&res){
        if(curr.size() == nums.size()){
            res.push_back(curr);
            return;
        }

        
        
        for(int i = 0; i < nums.size(); i++){
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]){
                continue;
            }
            if(!used[i]){
                used[i] = true;
                curr.push_back(nums[i]);
                backtracking(nums, curr, res);
                curr.pop_back();
                used[i] = false;
            }
            
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        used.resize(nums.size());
        backtracking(nums, curr, res);
        return res;
    }
};