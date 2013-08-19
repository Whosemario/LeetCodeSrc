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
    bool dfs(TreeNode* root, int sum, int target){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL){
            if(sum + root->val ==target) return true;
            else return false;
        }
        
        return dfs(root->left,sum+root->val,target) || dfs(root->right,sum+root->val,target);
    }
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return false;
        return dfs(root,0,sum);
    }
};