class Solution {
private:
    int binary(long long x){
        long long low = 0, high = x;
        while(low<=high){
            long long mid = (low+high)/2;
            if(mid*mid==x) return (int)mid;
            else if(mid*mid>x) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
public:
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(x>=0);
        if(x<=1) return x;
        return binary(x);
    }
};