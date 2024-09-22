class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int h_index = 0;
        for(int i = 0; i < citations.size(); i++){
            if(citations[i] > n - i)
                h_index = max(h_index, n - i);
            else
                h_index = max(h_index, citations[i]);
        }
        return h_index;
    }
};