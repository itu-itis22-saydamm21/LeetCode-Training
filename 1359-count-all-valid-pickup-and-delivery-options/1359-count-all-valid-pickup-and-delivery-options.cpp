#define MOD 1000000007
class Solution {
       
public:
    int countOrders(int n) {
        long long box = n * 2;
        long long res = 1;
        while(box){
            res = res * (box * (box - 1) / 2) % MOD;
            box -= 2;
        }
        return res;
    }
};