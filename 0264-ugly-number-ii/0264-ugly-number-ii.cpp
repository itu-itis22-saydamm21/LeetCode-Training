class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>  ugly_numbers(n);
        ugly_numbers[0] = 1;
        int ptr_2 = 0, ptr_3 = 0, ptr_5 = 0;
        for(int i = 1; i < n; i++){
            ugly_numbers[i] = min({ugly_numbers[ptr_2] * 2, ugly_numbers[ptr_3] * 3, ugly_numbers[ptr_5] * 5});
            if(ugly_numbers[i] == ugly_numbers[ptr_2] * 2) ptr_2++;
            if(ugly_numbers[i] == ugly_numbers[ptr_3] * 3) ptr_3++;
            if(ugly_numbers[i] == ugly_numbers[ptr_5] * 5) ptr_5++;
        }
        return ugly_numbers[n - 1];
    }
};