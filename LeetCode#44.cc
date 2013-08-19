class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n<=1) return true;
        int _max = A[0];
        for(int i=0;i<n&&i<=_max;i++){
            if(_max>=n-1) return true;
            if(A[i]+i>_max)
                _max=A[i]+i;
        }
        
        return _max>=n-1?true:false;
    }
};