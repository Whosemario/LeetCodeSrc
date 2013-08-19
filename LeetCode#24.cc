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
    ListNode* reverseList(ListNode* head, int k){
        ListNode* pre = NULL;
        ListNode* cur = head;
        int cnt = 0;
        while(++cnt <= k && cur!=NULL){cur=cur->next;}
        if(cnt<=k) return head;
        cur = head;
        cnt=0;
        while(cnt++ < k && cur!=NULL){
            ListNode* t = cur->next;
            cur->next = pre;
            pre = cur;
            cur = t;
        }
        head->next = cur;
        return pre;
    }
    
    ListNode* dfs(ListNode* node, int k, int num){
        if(node==NULL) return NULL;
        ListNode* t = dfs(node->next,k,num+1);
        node->next = t;
        if(num%k==1){
            return reverseList(node,k);
        }
        else return node;
    }
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
        if(k<=1) return head;
        return dfs(head,k,1);
    }
};