class Solution {
public:
    bool isPalindrome(string s) {
        string newstr;
        for(auto c : s){
           if(c >= 'A' && c <= 'Z')
               newstr += c + 32;
           else if((c >= 'a' && c <= 'z') || isdigit(c))
               newstr += c;
        }
        stack<char> st;
        queue<char> q;
        for(auto c : newstr){
            st.push(c);
            q.push(c);
        }
        while(!st.empty()){
            if(q.front() != st.top())
                break;
            q.pop();
            st.pop();
        }
        if(st.empty())
            return true;
        else 
            return false;
    }
};