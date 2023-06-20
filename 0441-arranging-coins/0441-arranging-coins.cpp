class Solution {
public:
    long long key;
    
    long long calc(long long n) {return((n * (n + 1))/2);}
    
    long long binSrc(long long l, long long r){
        long long mid = (l + r) / 2;
        long long result = calc(mid);
        long long result2 = calc(mid + 1);
        
        if (result > key)
            return binSrc(l, mid - 1);
        else if (result <= key && result2 > key)
            return mid;
        else
            return binSrc(mid + 1, r);
    }
    long long arrangeCoins(int coins) {
        key = coins;
        return binSrc(0, key);
    }
};