
int lengthOfLongestSubstring(char *s) {
    int freq[256] = {0};
    int l = 0, r = -1;
    int res = 0;
    while (s[l]) {
        if (r + 1 < (int)strlen(s) && freq[s[r + 1]] == 0) {
            freq[s[++r]]++;
        } else {
            freq[s[l++]]--;
        }
        res = fmax(res, r - l + 1);
    }
    return res;
}
