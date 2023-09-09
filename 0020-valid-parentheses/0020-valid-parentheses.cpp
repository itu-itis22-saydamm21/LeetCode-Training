class Solution {
public:
    bool isValid(string s) {
       unordered_map<char,char> mp = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> par;
        for(char c: s){
            if(mp.find(c) != mp.end() && !par.empty()){
                if(par.top() != mp[c])
                   return false;
                par.pop();
            }
            else
                par.push(c);
        }
        return par.empty();
    }
};