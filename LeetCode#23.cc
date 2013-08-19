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
    ListNode * dfs(ListNode* node, int num){
        if(node==NULL) return NULL;
        ListNode* t = dfs(node->next,num+1);
        node->next = t;
        if(num&1){
            if(node->next==NULL) return node;
            else{
                ListNode* tmp = node->next;
                node->next=tmp->next;
                tmp->next = node;
                return tmp;
            }
        }
        else return node;
    }
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        return dfs(head,1);
    }
};