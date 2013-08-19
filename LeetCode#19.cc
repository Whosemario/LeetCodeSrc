/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int dfs(ListNode* root, int n){
        if(root==NULL) return 0;
        int num = dfs(root->next,n);
        if(num==n){
            root->next = root->next->next;
        }
        return num+1;
    }
    
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
        int num = dfs(head,n);
        if(num==n) return head->next;
        else return head;
    }
};