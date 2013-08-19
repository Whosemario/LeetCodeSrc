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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode* ret = NULL;
        ListNode* tail = NULL;
        int size = lists.size();
        if(size==0) return ret;
        if(size==1) return lists[0];
        while(true){
            int ind = -1;
            for(int i=0;i<size;i++)
                if(lists[i]!=NULL){
                    if(ind==-1 || lists[i]->val < lists[ind]->val)
                        ind = i;
                }
            if(ind==-1) break;
            if(ret==NULL){
                ret = tail = lists[ind];
                lists[ind]=lists[ind]->next;
            }
            else{
                tail->next = lists[ind];
                tail = tail->next;
                lists[ind] = lists[ind]->next;
            }
        }
        if(tail) tail->next = NULL;
        return ret;
    }
};