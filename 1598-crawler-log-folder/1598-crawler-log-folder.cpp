class Solution {
public:
    int minOperations(vector<string>& logs) {
        bool parent = true;
        int first = 0;
        for(auto log : logs){
            if(log == "./" || (log == "../" && parent))
                ;
            else if(log == "../" && !parent){
                first--;
                if(!first) parent = true;
            }
            else{
                if(!first) parent = false;
                first++;
            }
        }
        return first;
    }
};