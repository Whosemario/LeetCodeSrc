class Solution {
public:
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(divisor);
        if(dividend==0 ) return 0;
        int neg = (dividend > 0) ^ (divisor > 0);
        
        long long a = dividend>0?(long long)dividend:-((long long)(dividend));
        long long b = divisor>0?(long long)divisor:-((long long)(divisor));
        
        long long ret = 0;
        while(a>=b){
            long long c = b;
            for(int i=0;a>=c;++i,c<<=1){
                a-=c;
                ret+=1<<i;
            }
        }
        if(neg) ret=-ret;
        return (int)ret;
    }
};