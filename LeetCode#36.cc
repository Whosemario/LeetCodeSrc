class Solution {
private:
    bool isZero(string& num){
        if(num.length()==1 && num[0]=='0')
            return true;
        return false;
    }
    
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(isZero(num1) || isZero(num2)) return "0";
        string ret;
        int len1 = num1.length();
        int len2 = num2.length();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int j=0;j<len2;j++){
            int c = 0;
            for(int i=0;i<len1;i++){
                int v = (num1[i]-'0')*(num2[j]-'0')+c;
                if(i+j==ret.length()){
                    ret+=(char)(v%10+'0');
                    c=v/10;
                }
                else{
                    v += ret[i+j]-'0';
                    ret[i+j]=(char)(v%10+'0');
                    c=v/10;
                }
            }
            if(c){
                ret+=(char)(c+'0');
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};