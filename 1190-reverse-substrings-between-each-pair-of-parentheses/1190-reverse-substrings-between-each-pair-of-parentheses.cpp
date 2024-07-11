class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                int start = st.top();
                st.pop();
                reverse(s.begin() + start, s.begin() + i);
            }
        }
        string res;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == ')') continue;
            res += s[i];
        }
        return res;
    }
};