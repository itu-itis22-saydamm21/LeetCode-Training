class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream iss(input);
        string token;
        stack<int>  depth_stack;
        depth_stack.push(0);
        
        int max_len = 0;
        while(getline(iss, token, '\n')){
            int depth = 0;
            while(token[depth] == '\t'){
                depth++;
            }
            int len = token.size() - depth;
            while(depth_stack.size() > depth + 1)
                depth_stack.pop();
            if(depth == 0)
                depth_stack.push(len);  
            else
                depth_stack.push(depth_stack.top() + len + 1);
            if(token.find('.') != string::npos)
                max_len = max(max_len, depth_stack.top());
        }
        return max_len;
    }
};