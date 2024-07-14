class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<tuple<int,int,char,int>> robots; //pos, health, dir, idx
        
        for(int i = 0; i < n; i++){
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        sort(robots.begin(), robots.end());
        stack<tuple<int,int,char,int>> st;
        vector<int> res(n, -1);
        for(auto& [pos, health, dir, idx] : robots){
            
            if(dir == 'R'){
                st.push({pos, health, dir, idx});
            }
            else{
                while(!st.empty()){
                    auto [r_pos, r_health, r_dir, r_idx] = st.top();
                    if(health > r_health){
                        r_health = -1;
                        health--;
                        st.pop();
                    }
                    else if(r_health > health){
                        health = -1;
                        r_health--;
                        st.pop();
                        st.push({r_pos, r_health, r_dir, r_idx});
                        break;
                    }
                    else{
                        r_health = -1;
                        health = -1;
                        st.pop();
                        break;
                    }
                }
                if(health > 0)
                    res[idx] = health;
            }
        }
        
        while(!st.empty()){
            auto [rem_pos, rem_health, rem_dir, rem_idx] = st.top();
            st.pop();
            res[rem_idx] = rem_health;
        }
        vector<int> survivors;
        for(auto &r : res){
            if (r != -1)
                survivors.push_back(r);
        }
        return survivors;
    }
};