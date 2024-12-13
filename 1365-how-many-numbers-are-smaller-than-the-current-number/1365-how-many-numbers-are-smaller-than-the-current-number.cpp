class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        map<int,int> mp;
        
        for(int i = 0; i < arr.size(); i++){
            if(mp.find(arr[i]) == mp.end())
                mp[arr[i]] = i;
        }
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++){
            res.push_back(mp[nums[i]]);
        }
        return res;
    }
};