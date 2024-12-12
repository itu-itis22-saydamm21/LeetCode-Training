class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,int> mp;
        vector<int> res;
        for(int i =0 ; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 1; i <= nums.size(); i++){
            if(mp[i] == 0)
                res.push_back(i);
        }
        return res;
    }
};