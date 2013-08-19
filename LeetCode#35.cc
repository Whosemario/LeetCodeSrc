class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=2) return 0;
        
        int left = 0, right = n-1;
        int leftv = A[0], rightv = A[n-1];
        int ret = 0;
        while(left<right){
            ret += leftv-A[left]+rightv-A[right];
            if(leftv <= rightv){
                left++;
                if(A[left]>leftv) leftv = A[left];
            }
            else{
                right--;
                if(A[right]>rightv) rightv = A[right];
            }
        }
        
        return ret;
    }
};