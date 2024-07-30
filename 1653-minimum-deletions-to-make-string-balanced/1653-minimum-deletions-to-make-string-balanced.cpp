class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> pref_b(n + 1, 0);
        for(int i = 0; i < n; i++){
            pref_b[i + 1] = pref_b[i] + (s[i] == 'b' ? 1 : 0);
        }
        vector<int> suff_a(n + 1, 0);
        for(int i = n - 1; i >= 1; i--){
            suff_a[i - 1] = suff_a[i] + (s[i] == 'a' ? 1 : 0);
        }
        
        int min_op = INT_MAX;
        for(int i = 0; i <= n; i++){
            min_op = min(min_op, pref_b[i] + suff_a[i]);
        }
        return min_op;
    }
};