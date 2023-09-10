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
    vector<int> v;
public:
    TreeNode*    subTree(int left, int right){
        if(left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left = subTree(left, mid - 1);
        root->right = subTree(mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        v = nums;
        return(subTree(0, nums.size() - 1));
    }
};