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
    void dfs(TreeNode* root,vector<int> cell, vector<vector<int> >& res,int sum,int target){
        if(root==NULL) return ;
        if(root->left==NULL && root->right==NULL){
            if(sum+root->val == target){
                cell.push_back(root->val);
                res.push_back(cell);
            }
            return ;
        }
        cell.push_back(root->val);
        if(root->left){
            dfs(root->left,cell,res,sum+root->val,target);
        }
        if(root->right){
            dfs(root->right,cell,res,sum+root->val,target);
        }
        return ;
    }
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        
        dfs(root,vector<int>(),ret,0,sum);
        
        return ret;
    }
};