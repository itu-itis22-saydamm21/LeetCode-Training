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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        if(!root)
            return cnt;
        countgoodnode(root, cnt, root->val);
        return cnt;   
    }
    
    void    countgoodnode(TreeNode *node, int &cnt, int maxvalfornow){
        if(!node)
            return;
        if(node->val >= maxvalfornow){
            cnt++;
            maxvalfornow = node->val;
        }
        countgoodnode(node->left, cnt, maxvalfornow);
        countgoodnode(node->right, cnt, maxvalfornow);
    }
};