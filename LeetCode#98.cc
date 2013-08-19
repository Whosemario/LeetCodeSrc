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
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        vector<vector<TreeNode*> > que;
        
        if(root==NULL) return ret;
        
        int head = 0;
        
        ret.push_back(vector<int>(1,root->val));
        que.push_back(vector<TreeNode*>(1,root));
        
        while(head < ret.size()){
            vector<int> val;
            vector<TreeNode*> node;
            if(head&1){
                for(int i=ret[head].size()-1;i>=0;i--){
                    TreeNode* u = que[head][i];
                    if(u->left){
                        val.push_back(u->left->val);
                        node.push_back(u->left);
                    }
                    if(u->right){
                        val.push_back(u->right->val);
                        node.push_back(u->right);
                    }
                }
            }
            else{
                for(int i=ret[head].size()-1;i>=0;i--){
                    TreeNode* u = que[head][i];
                    if(u->right){
                        val.push_back(u->right->val);
                        node.push_back(u->right);
                    }
                    if(u->left){
                        val.push_back(u->left->val);
                        node.push_back(u->left);
                    }
                }
            }
            head++;
            if(val.size()){
                ret.push_back(val);
                que.push_back(node);
            }
        }
        
        return ret;
    }
};