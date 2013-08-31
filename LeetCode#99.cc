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
private:
    TreeNode* dfs(TreeNode* root){
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL) return root;
        if(root->left==NULL) return dfs(root->right);
        else if(root->right==NULL){
            root->right = root->left;
            TreeNode* ret =  dfs(root->left);
            root->left = NULL;
            return ret;
        }
        else{
            TreeNode* ret = dfs(root->left);
            ret->right = root->right;
            ret = dfs(root->right);
            root->right = root->left;
            root->left = NULL;
            return ret;
        }
    }
    
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return ;
        dfs(root);
    }
};