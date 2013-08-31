class Solution {
private:
    bool isNumber(string str,bool f=false){
        int k=0;
        if(str.length()==0) return true;
        if(str[0]=='-'||str[0]=='+' ) k++;
        if(k==str.length()) return false;
        if(str[k]=='.'&&k==str.length()-1) return false;
        
        bool flag = false;
        while(k<str.length()){
            if(str[k]=='.'&&flag) return false;
            if(str[k]=='.') flag=true;
            else if(str[k]<'0' || str[k]>'9') return false;
            k++;
        }
        if(f&&flag) return false;
        return true;
    }
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool ret = true;
        if(s==NULL) return false;
        int len = strlen(s);
        int k = 0;
        while(k<len&&s[k]==' ') k++;
        if(k==len) return false;
        string num = "";
        bool flag=false;
        while(k<len){
            if(s[k]=='e'&&flag==false){
                if(num!=""){
                    ret = isNumber(num);
                    if(ret==false) return false;
                    num="";
                }
                else return false;
                flag = true;
            }
            else if(s[k]==' ') break;
            else num+=s[k];
            k++;
        }
        if(num!=""){
            ret = isNumber(num,flag);
            if(ret==false) return false;
        }
        else return false;
        
        while(k<len&&s[k]==' ') k++;
        return k==len;
    }
};