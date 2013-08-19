class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = digits.size();
        vector<int> ret ;
        int c = 0;
        for(int i = size-1;i>=0;i--){
            if(i==size-1){
                c = digits[i]+1;
                ret.push_back(c%10);
                c=c/10;
            }
            else{
                c+=digits[i];
                ret.push_back(c%10);
                c/=10;
            }
        }
        if(c) ret.push_back(c);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};