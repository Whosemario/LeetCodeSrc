class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<n;i++)
            if(A[i]!=i+1){
                int cur = A[i];
                A[i]=-1;
                while(cur>0 && cur<=n && A[cur-1]!=cur){
                    int tmp = A[cur-1];
                    A[cur-1]=cur;
                    cur = tmp;
                }
            }
        for(int i=0;i<n;i++)
            if(A[i]==-1) return i+1;
        return n+1;
    }
};