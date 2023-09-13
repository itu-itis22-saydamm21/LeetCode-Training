class Solution {
    bool    canShip(const vector<int>& weights, int days, int capacity){
        int currDay = 1;
        int currCapacity = 0;
        
        for (int weight : weights){
            if(currCapacity + weight > capacity){
                currDay++;
                currCapacity = 0;
            }
            currCapacity += weight;
        }
        
        return currDay <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        int mid = 0;
        while(left < right){
            mid = (left + right) / 2;
            
            if(canShip(weights, days, mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};