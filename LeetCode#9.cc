class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(x == 0) return true;
        if( x<0) return false;
        long long res = 0;
        long long tmp = x;
        while(x){ res = res*10 + x%10;x/=10;}
        if(res==tmp) return true;
        return false;
    }
};