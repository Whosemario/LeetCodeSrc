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
    bool dfs(TreeNode* root, int& pre, bool& flag){
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL){
            if(flag==false || root->val > pre){
                pre = root->val;
                flag = true;
                return true;
            }
            else return false;
        }
        else if(root->left==NULL){
            if(flag==false || root->val > pre){
                flag = true;
                pre = root->val;
            }
            else return false;
            return dfs(root->right,pre,flag);
        }
        else if(root->right==NULL){
            bool r = dfs(root->left,pre,flag);
            if(r==false) return false;
            if(flag==false || root->val > pre){
                flag = true;
                pre = root->val;
                return true;
            }
            else return false;
        }
        else{
            bool r = dfs(root->left,pre,flag);
            if(r==false) return false;
            if(flag==false || root->val > pre){
                flag = true;
                pre = root->val;
            }
            else return false;
            return dfs(root->right,pre,flag);
        }
    }
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return true;
        bool flag = false;
        int pre = -1;
        return dfs(root,pre,flag);
    }
};