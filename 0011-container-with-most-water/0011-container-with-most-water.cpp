class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        int curr_area;
        while(left < right){
            curr_area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, curr_area);
            height[left] < height[right] ? left++ : right--;
        }
        return max_area;
    }
};