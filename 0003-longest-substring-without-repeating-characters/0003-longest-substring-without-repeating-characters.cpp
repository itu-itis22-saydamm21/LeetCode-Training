class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)
            return 0;
        int size = 1;
        for(int l = 0; l < s.size(); l++){
            int tmp = 1;
            unordered_map<char, int> mp(0);
            mp[s[l]] = 1;
            for(int r = l + 1; r < s.size(); r++){
                mp[s[r]]++;
                if(mp[s[r]] == 1){
                    tmp++;
                }
                else
                    break;
            }
            size = max(tmp, size);
        }
        return size;
    }
};