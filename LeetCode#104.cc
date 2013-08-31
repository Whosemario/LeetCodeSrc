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
    int ind ;
    void dfs(TreeNode*& root, int left, int right,
            vector<int>& inorder,vector<int>& postorder){
                if(left>right) return ;
                int k ;
                for(k=left;k<=right;k++)
                    if(inorder[k]==postorder[ind]) break;
                ind--;
                root = new TreeNode(inorder[k]);
                dfs(root->right,k+1,right,inorder,postorder);
                dfs(root->left,left,k-1,inorder,postorder);
                return ;
            }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(inorder.size()==0) return NULL;
        ind = inorder.size()-1;
        TreeNode* ret = NULL;
        dfs(ret,0,ind,inorder,postorder);
        return ret;
    }
};