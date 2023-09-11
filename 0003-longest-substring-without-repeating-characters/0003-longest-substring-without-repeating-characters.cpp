class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.size() == 0)
           return 0;
       unordered_map<char, int> mp;
       int l = 0, r = 0;
       int size = 1;
       while(s[l]){
           if(r < s.size() && mp[s[r]] == 0){
               mp[s[r++]]++;
           }
           else{
               mp[s[l++]]--;
           }
           size = max(size, r - l);
       }
       return size;
    }
};