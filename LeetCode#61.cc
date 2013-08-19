class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1) return ;
        int head = 0,tail = n-1;
        while(tail>=0&&A[tail]==2) --tail;
        
        for(int i=0;i<=tail;i++){
            if(A[i]==0){
                int tmp = A[head];
                A[head]=A[i];
                A[i]=tmp;
                head++;
            }
            else if(A[i]==2){
                int tmp = A[tail];
                A[tail--]=A[i];
                A[i]=tmp;
                i--;
            }
        }
        
        return ;
    }
};