class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long ret = 0;
        long long maxint = 1L<<31-1;
        int flag = 1;
        if(x==0) return 0;
        if(x<0) {flag = -1;x=-x;}
        while(x){
            ret = ret*10+x%10;
            x/=10;
        }
        if(ret>maxint) throw new overflow_error("Overflow");
        return (int)(flag*ret);
    }
};