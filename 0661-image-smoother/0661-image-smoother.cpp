class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int w = img[0].size();
        int h = img.size();
        vector<vector<int>> res(h, vector<int>(w, 0));
        for(int j = 0; j < h; j++){
            for(int i = 0; i < w; i++){
                int sum = 0;
                int count = 1;
                sum += img[j][i];
                if(i - 1 >= 0){
                    sum += img[j][i - 1];
                    count++;
                }
                if(i + 1 < w){
                    sum += img[j][i + 1];
                    count++;
                }
                if(j - 1 >= 0){
                    sum += img[j - 1][i];
                    count++;
                }
                if(j + 1 < h){
                    sum += img[j + 1][i];
                    count++;
                }
                if(i - 1 >= 0 && j - 1 >= 0){
                    sum += img[j - 1][i - 1];
                    count++;
                }
                if(i + 1 < w && j - 1 >= 0){
                    sum += img[j - 1][i + 1];
                    count++;
                }
                if(i - 1 >= 0 && j + 1 < h){
                    sum += img[j + 1][i - 1];
                    count++;
                }
                if(i + 1 < w && j + 1 < h){
                    sum += img[j + 1][i + 1];
                    count++;
                }
                res[j][i] = sum / count; 
            }
        }
        return res;
    }
};