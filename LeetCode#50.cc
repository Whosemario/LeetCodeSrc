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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return head;
        int len = 0;
        ListNode* tail = head;
        len=1;
        while(tail->next!=NULL){++len;tail=tail->next;}
        k=k%len;
        if(k==0) return head;
        int cnt = 0;
        ListNode* cur = head;
        while(cur){
            cnt++;
            if(cnt==len-k) break;
            cur = cur->next;
        }
        tail->next = head;
        head = cur->next;
        cur->next = NULL;
        return head;
    }
};