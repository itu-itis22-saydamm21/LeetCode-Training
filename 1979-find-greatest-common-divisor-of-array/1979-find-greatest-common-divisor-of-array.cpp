class Solution {
public:
    int gcd(int m, int n){
        if(m % n == 0) return n;
        else return gcd(n, m % n);
    }
    
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        int largest = nums[nums.size() - 1];
        return gcd(smallest, largest);
    }
};