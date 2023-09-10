class Solution {
public:
    double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    } 
    else if (n < 0) {
        x = 1 / x;
        if(n == -2147483648){
            n = 2147483647;
            if(x == -1)
                return 1.0;
        }
        else
            n = -n;
    }
    double result = 1.0;
    while (n > 0) {
        if (n % 2 == 0) {
            x *= x;
            n /= 2;
        } else {
            result *= x;
            n--;
        }
    }

    return result;
}
};