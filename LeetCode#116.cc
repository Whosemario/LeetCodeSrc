/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode* Next = NULL;
        TreeLinkNode* Prev = NULL;
        
        while(root){
            for(;root;root=root->next){
                if(!Next) Next = root->left ? root->left:root->right;
                if(root->left){
                    if(Prev) Prev->next = root->left;
                    Prev = root->left;
                }
                if(root->right){
                    if(Prev) Prev->next = root->right;
                    Prev = root->right;
                }
            }
            root=Next;
            Prev=Next = NULL;
        }
    }
};