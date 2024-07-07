class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drink = 0;
        int empty = 0;
        while(numBottles){
            drink += numBottles;
           // cout << numBottles << " " << empty << endl;
            numBottles += empty;
            empty = numBottles % numExchange;
            numBottles = numBottles / numExchange;
        }
        return drink;
    }
};