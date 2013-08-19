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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* head = NULL, * tail = NULL;
        int c = 0;
        while(l1&&l2){
            ListNode* tmp = new ListNode((l1->val+l2->val+c)%10);
            c = (l1->val+l2->val+c)/10;
            if(head){
                tail->next = tmp;
                tail = tmp;
            }
            else{
                head = tail = tmp;
            }
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1){
            ListNode* tmp = new ListNode((l1->val+c)%10);
            c = (l1->val+c)/10;
            if(head){
                tail->next = tmp;
                tail= tmp;
            }
            else{
                head = tail = tmp;
            }
            l1= l1->next;
        }
        
        while(l2){
            ListNode* tmp = new ListNode((l2->val+c)%10);
            c = (l2->val+c)/10;
            if(head){
                tail->next = tmp;
                tail= tmp;
            }
            else{
                head = tail = tmp;
            }
            l2= l2->next;
        }
        if(c){
            ListNode* tmp =new ListNode(c);
            tail->next = tmp;
        }
        return head;
    }
};