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
    int dfs(TreeNode* root, int& res,bool& flag){
        if(root==NULL) return 0;
        int l=0,r=0;
        if(root->left)
            l = dfs(root->left,res,flag);
            
        if(root->right)
            r = dfs(root->right,res,flag);
        
        int val = root->val;
        if(root->left && l >0) val+=l;
        if(root->right && r>0) val+=r;
        
        if(flag==false || val > res) {res = val;flag=true;}
        if(root->left==NULL) return root->val+(r>0?r:0);
        else if(root->right==NULL) return root->val+(l>0?l:0);
        else return l>r? (l>0?l:0)+root->val : (r>0?r:0)+root->val;
    }
public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        bool flag = false;
        dfs(root,ret,flag);
        return ret;
    }
};