class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++){
            string tmp = "";
            while(s[i] != ' ' && s[i] != '\0'){
                tmp += s[i];
                i++;
            }
            reverse(tmp.begin(), tmp.end());
            res += tmp;
            if(s[i] == ' ')
                res += ' ';
        }
        return res;
    }
};