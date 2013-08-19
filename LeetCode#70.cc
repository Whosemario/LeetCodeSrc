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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head1 =NULL ,*tail1=NULL, *head2=NULL, *tail2=NULL;
        
        if(head==NULL) return NULL;
        
        while(head){
            if(head->val < x){
                if(head1==NULL){
                    head1 = tail1 = head;
                }
                else{
                    tail1->next = head;
                    tail1 = head;
                }
            }
            else{
                if(head2==NULL){
                    head2 = tail2 = head;
                }
                else{
                    tail2->next = head;
                    tail2 = head;
                }
            }
            head = head->next;
        }
        
        if(head1==NULL) head1 = head2;
        else tail1->next = head2;
        
        if(head2!=NULL) tail2->next = NULL;
        
        return head1;
    }
};