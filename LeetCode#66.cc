class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(A);
        if(n==0) return 0;
        int j=1;
        int cnt=1;
        for(int i=1;i<n;i++)
            if(A[i]==A[i-1]){
                cnt++;
                if(cnt<=2)
                    A[j++]=A[i];
            }
            else{
                cnt=1;
                A[j++]=A[i];
            }
            
        return j;
    }
};