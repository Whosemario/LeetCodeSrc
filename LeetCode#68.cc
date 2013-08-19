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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
        ListNode* ret=NULL, *tail;
        
        int cnt=1;
        while(head){
            if(head->next==NULL || head->val != head->next->val){
                if(cnt==1){
                    if(ret==NULL){
                        ret = tail = head;
                    }
                    else{
                        tail->next = head;
                        tail = head;
                    }
                }
                cnt=1;
            }
            else cnt++;
            
            head = head->next;
        }
        
        if(ret)
            tail->next = NULL;
        
        return ret;
    }
};