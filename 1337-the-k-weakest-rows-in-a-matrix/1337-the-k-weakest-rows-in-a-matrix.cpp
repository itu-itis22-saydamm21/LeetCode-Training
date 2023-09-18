class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> q;

        int rows = mat.size();
        vector<int> dp(rows);

        for (int i = 0; i < rows; i++) {
            int ones = accumulate(mat[i].begin(), mat[i].end(), 0);
            q.push({ones, i});
        }

        vector<int> res;
        while (!q.empty() && k > 0) {
            res.push_back(q.top().second);
            q.pop();
            k--;
        }

        return res;
    }
};
