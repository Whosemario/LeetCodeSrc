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
    void dfs(TreeNode* root , int depth , int& res){
        if(root == NULL) return ;
        if(root->left==NULL && root->right==NULL){
            if(res == -1 || depth+1 < res)
                res = depth+1;
            return ;
        }
        dfs(root->left,depth+1,res);
        dfs(root->right,depth+1,res);
    }
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        int ret = -1;
        dfs(root,0,ret);
        
        return ret;
    }
};