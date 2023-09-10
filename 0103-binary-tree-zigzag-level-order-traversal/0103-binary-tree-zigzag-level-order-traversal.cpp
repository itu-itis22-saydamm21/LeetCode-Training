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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(!root)
            return result;
        queue<TreeNode*> node;
        node.push(root);
        bool r_to_l = true;
        while(!node.empty()){
            vector<int> temp;
            int size = node.size();
            while(size--){
                TreeNode* curr = node.front();
                node.pop();
                temp.push_back(curr->val);
                if(curr->left)
                    node.push(curr->left);
                if(curr->right)
                    node.push(curr->right);
            }
            if(!r_to_l)
               reverse(temp.begin(), temp.end());
            r_to_l = !r_to_l;
            result.push_back(temp);
        }
        return result;
    }
};