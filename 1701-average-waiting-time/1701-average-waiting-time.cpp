class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double start = customers[0][0];
        double time = customers[0][1];
        double waiting = time;
        start += time;
        for(int i = 1; i < customers.size(); i++){
            
            if(start > customers[i][0]){
                waiting += start + customers[i][1] - customers[i][0];
            }
            else{
                start = customers[i][0];
                waiting += customers[i][1];     
            }
            start += customers[i][1];
        }
        return(double(waiting) / double(customers.size()));
    }
};