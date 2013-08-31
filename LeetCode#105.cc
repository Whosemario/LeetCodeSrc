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
    int ind;
    TreeNode* dfs(int left,int right,
        vector<int>& preorder,vector<int>& inorder){
            if(left>right) return NULL;
            int k=0;
            for( k=left;k<=right;k++){
                if(preorder[ind]==inorder[k]) break;
            }
            ind++;
            TreeNode* root = new TreeNode(inorder[k]);
            root->left = dfs(left,k-1,preorder,inorder);
            root->right = dfs(k+1,right,preorder,inorder);
            return root;
        }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size()==0 || preorder.size()==0) return NULL;
        TreeNode* ret ;
        ind = 0;
        ret = dfs(0,inorder.size()-1,preorder,inorder);
        return ret;
        
    }
};