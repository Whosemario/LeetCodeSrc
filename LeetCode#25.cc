class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(A!=NULL);
        if(n<=1) return n;
        int i = 1;
        for(int j=1;j<n;j++)
            if(A[j]!=A[j-1]) A[i++]=A[j];
        return i;
    }
};