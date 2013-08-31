class Solution {
private:
    bool binary(int A[],int l, int r, int target){
        int low = l, high = r;
        while(low <= high){
            int mid = (low+high)/2;
            if(A[mid]==target) return true;
            else if(target < A[mid]) high = mid-1;
            else low = mid+1;
        }
        return false;
    }
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return false;
        if(n==1) return A[0]==target;
        
        int l,r;
        if(A[0]<A[n-1]) return binary(A,0,n-1,target);
        else if(A[0]>A[n-1]){l=0;r=n-1;}
        else{
            if(A[0]==target) return true;
            l = 1;
            while(l<n && A[l]==A[l-1]) l++;
            if(l==n) return A[0]==target;
            if(A[l]<A[0]) return binary(A,l,n-1,target);
            
            r=n-2;
            while(r>=0&&A[r]==A[r+1]) r--;
            if(A[r] > A[n-1]) return binary(A,l,r,target);
        }
        
        int low = l, high = r;
        
        while(low<=high){
            int mid = (low+high)/2;
            if(A[mid]>=A[l]) low=mid+1;
            else high = mid-1;
        }
        
        return binary(A,l,high,target) || binary(A,high+1,r,target);
    }
};