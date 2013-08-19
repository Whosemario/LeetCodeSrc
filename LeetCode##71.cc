class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0&&n==0) return ;
        vector<int> tmp(m+n);
        
        int i=0,j=0,k=0;
        while(i<m&&j<n){
            if(A[i]<=B[j]) tmp[k++]=A[i++];
            else tmp[k++]=B[j++];
        }
        
        while(i<m) tmp[k++]=A[i++];
        while(j<n) tmp[k++]=B[j++];
        
        for(int i=0;i<k;i++)
            A[i]=tmp[i];
        
    }
};