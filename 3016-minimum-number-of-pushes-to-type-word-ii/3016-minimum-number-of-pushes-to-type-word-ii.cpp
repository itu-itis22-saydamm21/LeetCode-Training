class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mp;
        for(int i = 0; i < word.size();i++){
            mp[word[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for(auto &m : mp){
            pq.push({m.second, m.first});
        }
        
        int cnt = 0;
        int k = 0;
        while(!pq.empty()){
            auto &[freq, letter] = pq.top();
            if(k / 8 == 0){
               cnt += freq;
            }
            else if(k / 8 == 1){
               cnt += freq * 2;
            }
            else if(k / 8 == 2)
               cnt += freq * 3;
            else if(k / 8 == 3)
               cnt += freq * 4;
            k++;
            pq.pop();
        }
        return cnt;
    }
};