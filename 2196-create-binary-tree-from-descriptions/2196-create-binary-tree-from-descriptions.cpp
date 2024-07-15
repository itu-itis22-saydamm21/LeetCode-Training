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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        map<int, int> children_count; 
        for(auto &des : descriptions){
            int parent = des[0];
            int child = des[1];
            int isLeft = des[2];
            if(mp.find(parent) == mp.end()){
                mp[parent] = new TreeNode(parent);
            }
            if(mp.find(child) == mp.end()){
                mp[child] = new TreeNode(child);
            }
            if(isLeft == 1)
                mp[parent]->left = mp[child];
            else
                mp[parent]->right = mp[child];
            children_count[child]++;
        }
        
        TreeNode *root = nullptr;
        for(auto &des : descriptions){
            int parent = des[0];
            if(!children_count[parent])
                    root = mp[parent];
        }
        return root;
    }
};