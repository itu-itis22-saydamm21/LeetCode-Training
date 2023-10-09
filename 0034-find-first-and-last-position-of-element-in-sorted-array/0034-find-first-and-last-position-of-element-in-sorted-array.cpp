class Solution {
public:
    int findLeft(vector<int>& nums, int target){
        int left  = 0;
        int right = nums.size() - 1;
        int mid;
        int index = -1;
        while(left <= right){
            mid = (right + left) / 2;
            if(nums[mid] == target){
                index = mid;
                right = mid - 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return index;
    }
    
    int findRight(vector<int>& nums, int target){
        int left  = 0;
        int right = nums.size() - 1;
        int mid;
        int index = -1;
        while(left <= right){
            mid = (right + left) / 2;
            if(nums[mid] == target){
                index = mid;
                left = mid + 1;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = findLeft(nums, target);
        int right = findRight(nums, target);
        return {left, right};
    }
};