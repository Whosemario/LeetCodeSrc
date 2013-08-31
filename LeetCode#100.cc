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
    bool dfs(TreeNode* root, int& dep){
        if(root==NULL){
            dep=0;
            return true;
        }
        int ld,rd;
        bool f1 = dfs(root->left,ld);
        if(f1==false) return f1;
        bool f2 = dfs(root->right,rd);
        if(f2==false) return f2;
        
        if(abs(ld-rd)>1) return false;
        
        dep = max(ld,rd)+1;
        
        return true;
    }
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return true;
        int depth;
        return dfs(root,depth);
    }
};