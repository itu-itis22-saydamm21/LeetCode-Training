class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        unordered_map<int, int> mp;
        int len = 0;
        for(int i = 0; i < nums1.size(); i++){
            merged.push_back(nums1[i]);
            len++;
        }
        
        for(int i = 0; i < nums2.size(); i++){
            merged.push_back(nums2[i]);
            len++;
        }
        sort (merged.begin(), merged.end());
        if(len % 2 != 0)
            return (merged[len / 2]);
        else
            return ((double)(merged[len / 2] + merged[len / 2 - 1]) / 2);
    }
};