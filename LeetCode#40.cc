class Solution {
private:
    double pow(double x, long long n){
         if(n<0) return pow(1/x,-n);
        if(n==0) return 1;
        if(n==1) return x;
        
        double tmp = pow(x,n/2);
        tmp *=tmp;
        if(n&1) tmp*=x;
        return tmp;
    }
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return pow(x,(long long )n);
    }
};