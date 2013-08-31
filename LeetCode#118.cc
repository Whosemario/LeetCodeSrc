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
    TreeNode* n1;
    TreeNode* n2;
    
    TreeNode* prev;
    
    void dfs(TreeNode* root){
        if(root->left==NULL && root->right==NULL){
            if(prev && root->val < prev->val){
                if(n1==NULL){
                    n1 = prev;n2=root;
                }
                else{
                    n2 = root;
                }
            }
            prev = root;
            return ;
        }
            
            if(root->left) dfs(root->left);
            
            if(prev && root->val < prev->val){
                if(n1==NULL){
                    n1 = prev;n2=root;
                }
                else{
                    n2 = root;
                }
            }
            prev = root;
            
            if(root->right) dfs(root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n1 = n2 = NULL;
        prev = NULL;
        
        dfs(root);
        
        if(n1){
            int tmp = n1->val;
            n1->val = n2->val;
            n2->val = tmp;
        }
    }
};