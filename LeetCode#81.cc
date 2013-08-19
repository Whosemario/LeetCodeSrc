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
    void dfs(TreeNode* root, int val, int& res){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            val = val*10+root->val;
            res+=val;
            return ;
        }
        
        dfs(root->left,val*10+root->val,res);
        dfs(root->right,val*10+root->val,res);
        
    }
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        int ret = 0;
        dfs(root,0,ret);
        return ret;
    }
};