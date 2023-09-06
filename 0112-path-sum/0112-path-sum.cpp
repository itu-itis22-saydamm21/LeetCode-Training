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
    bool ret = false;
    int target;
public:
    void    dfs(TreeNode* node, int sum){
        if(!node || ret)
           return;
        sum += node->val;
        if(!node->right && !node->left){
            if(sum == target){
                ret = true;
            }
        }
        dfs(node->right, sum);
        dfs(node->left, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        target = targetSum;        
        dfs(root, 0);
        return ret;
    }
};