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
        ListNode* ret , *tail;
        ret = tail = head;
        
        while(tail->next){
            if(tail->val == tail->next->val)
                tail->next = tail->next->next;
            else
                tail = tail->next;
        }
        
        return ret;
    
    }
};