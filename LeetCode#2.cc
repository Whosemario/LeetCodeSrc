class Solution {
private:
    int count(int arr[], int s, int target,int isLeft){
        int low = 0, high = s-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(arr[mid] == target){
                if(isLeft) high = mid-1;
                else low = mid+1;
            }
            else if(arr[mid] > target) high = mid-1;
            else low = mid+1;
        }
        return high+1;
    }
    
    int findNth(int num, int A[], int m, int B[], int n){
            int high,mid,low;
            //A
            low = 0;high = m-1;
            while(low <= high){
                mid = (low+high)/2;
                int tmp = count(B,n,A[mid],1);
                if(tmp+mid+1 == num) return A[mid];
                else if(tmp + mid + 1 > num) high = mid-1;
                else low = mid+1;
            }
            //B
            low = 0; high = n-1;
            while(low<=high){
                mid = (low+high)/2;
                int tmp = count(A,m,B[mid],0);
                if(tmp+mid+1 == num) return B[mid];
                else if(tmp + mid + 1 > num) high = mid-1;
                else low = mid+1;
            }
            return -1;
    }
    
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = n+m;
        if(N&1){
            return findNth(N/2+1,A,m,B,n);
        }
        else{
            int a = findNth(N/2,A,m,B,n);
            int b = findNth(N/2+1,A,m,B,n);
            return (a*1.0+b)/2;
        }
    }
};