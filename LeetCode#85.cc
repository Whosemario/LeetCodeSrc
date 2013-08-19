/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<TreeNode*> sta;
        vector<int> ret;
        while(root!=NULL || !sta.empty()){
            if(root!=NULL){
                sta.push(root);
                root=root->left;
            }
            else{
                root = sta.top();
                sta.pop();
                ret.push_back(root->val);
                root=root->right;
            }
        }
        
        return ret;
    }
};