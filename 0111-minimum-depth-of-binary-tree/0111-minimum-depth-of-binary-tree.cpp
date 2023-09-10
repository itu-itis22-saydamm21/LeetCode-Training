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
    int minDepth(TreeNode* root) {
       if(!root)
           return 0;
       queue<TreeNode*> node;
       node.push(root);
       int depth = 1;
       int min_depth = INT_MAX;
       while(!node.empty()){
           int level_size = node.size();
           
           for(int i = 0; i < level_size; i++){
           TreeNode* curr = node.front();
           node.pop();
           if(!curr->right && !curr->left)
               min_depth = min(min_depth, depth);
           if(curr->left)
               node.push(curr->left);
           if(curr->right)
               node.push(curr->right);
           }
           depth++;
       }
        return min_depth;
    }
};