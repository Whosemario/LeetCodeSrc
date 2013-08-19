/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==n) return head;
        
        ListNode * pre = NULL;
        ListNode *cur = head;
        ListNode *pre1;
        ListNode *left;
        int cnt = 0;
        while(cur){
            cnt++;
            ListNode * next = cur->next;
            if(cnt == m){
                pre1 = pre;
                left = cur;
                pre = cur;
                cur = next;
            }
            else if(cnt > m && cnt <n){
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            else if(cnt == n){
                cur->next = pre;
                left->next = next;
                if(pre1) pre1->next=cur;
                else head = cur;
                cur = next;
            }
            else{
                pre = cur;
                cur = next;
            }
        }
        
        return head;
    }
};