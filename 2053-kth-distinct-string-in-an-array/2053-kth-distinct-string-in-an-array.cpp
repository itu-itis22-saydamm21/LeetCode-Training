class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;   
        }
        int s = 1;
        int i = 0, n = arr.size();
        while(i < n){
            while(i < n && mp[arr[i]] != 1) i++;
            if(i < n && s == k) return arr[i];
            s++;
            i++;
        }
        return "";
    }
};