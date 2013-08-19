class Solution {
private:
    int binarySearch(int A[], int n, int target){
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target==A[mid]) return mid;
            else if(target < A[mid]) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        return binarySearch(A,n,target);
    }
};