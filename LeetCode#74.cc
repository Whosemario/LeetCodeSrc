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
    void dfs(TreeNode* root,int depth, int& res){
        if(root==NULL){
            if(depth > res) res = depth;
            return ;
        }
        
        dfs(root->left,depth+1,res);
        dfs(root->right,depth+1,res);
    }
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return 0;
        int ret = 0;
        dfs(root,0,ret);
        
        return ret;
    }
};