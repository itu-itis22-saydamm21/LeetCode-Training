class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> charStack;
        unordered_map<char, int> lastOccurence;
        vector<bool> inStack(26, false);
        
        for(int i = 0; i < s.length(); i++)
            lastOccurence[s[i]] = i;
        
        for(int i = 0; i < s.length(); i++){
            char currentChar = s[i];
            
            if(inStack[currentChar - 'a'])
                continue;
            
            while(!charStack.empty() && currentChar < charStack.top() && i < lastOccurence[charStack.top()]){
                inStack[charStack.top() - 'a'] = false;
                charStack.pop();
            } 
            
            charStack.push(currentChar);
            inStack[currentChar - 'a'] = true;
        }
        
        string result = "";
        while(!charStack.empty()){
            result = charStack.top() + result;
            charStack.pop();
        }
        return result;
    }
};