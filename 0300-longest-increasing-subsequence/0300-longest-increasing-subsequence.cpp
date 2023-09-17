class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> piles;
        
        for(int i = 0; i < n; i++){
            int left = 0, right = piles.size();
            
            while(left < right){
                int mid = (left + right) / 2;
                if(piles[mid] < nums[i])
                    left = mid + 1;
                else
                    right = mid;
            }
       
            if(left == piles.size())
                piles.push_back(nums[i]);
            else
                piles[left] = nums[i];
        }
        
        return piles.size();
    }
};