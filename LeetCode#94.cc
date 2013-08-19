/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
    void dfs(TreeLinkNode* root){
        if(root==NULL) return ;
        TreeLinkNode* left = root->left;
        TreeLinkNode* right = root->right;
        while(left && right){
            left->next = right;
            left = left->right;
            right = right->left;
        }
        dfs(root->left);
        dfs(root->right);
    }
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(root==NULL) return ;
        
        dfs(root);
        
        return ;
    }
};