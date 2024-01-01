/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int> nums) {
        if(nums.empty())
            return nullptr;
        
        int maxIndex = finder_max_index(nums);
        
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root->left = constructMaximumBinaryTree(vector<int>(nums.begin(), nums.begin() + maxIndex));
        root->right = constructMaximumBinaryTree(vector<int>(nums.begin() + maxIndex + 1, nums.end()));
        
        return root;
    }
    
private:
    int finder_max_index(const vector<int> &nums){    
        int max = -1;
        int max_i = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
                max_i = i;
            }
        }
        return max_i;
    }
};