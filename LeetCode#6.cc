string ret ;
class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function  
        if(nRows==1) return s;  //Important
        ret = "";
        int len = s.length();
        for(int i=1;i<=nRows;i++){
            int ind = i;
            while(ind<=len){
                ret += s[ind-1];
                if(i==1 || i==nRows){
                    ind += nRows+nRows-2;
                }
                else{
                    int t = ind + nRows*2-i*2;
                    if(t <= len)
                       ret += s[t-1];
                    ind += nRows+nRows-2;
                }
            }
        }
        return ret;
    }
};