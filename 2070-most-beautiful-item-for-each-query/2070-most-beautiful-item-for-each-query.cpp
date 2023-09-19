class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        map<int, int> mp;
        
        sort(items.begin(), items.end());
        
        int n = items.size();
        int maxB = 0;;
        
        for(int i = 0; i < n; i++){
            maxB = max(maxB, items[i][1]);
            mp[items[i][0]] = maxB;
        }
     
        for(int q : queries){
            auto it = mp.upper_bound(q);
            if(it == mp.begin())
                ans.push_back(0);
            else{
                it--;
                ans.push_back(it->second);
            }
        }
        
        return ans;
    }
};