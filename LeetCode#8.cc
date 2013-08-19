class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        long long ret = 0;
        int flag = 1;
        while(*str == ' ' || *str=='\t') str++;
        if(*str=='-') {flag = -1;str++;}
        else if(*str=='+') str++;
        while(*str){
            if(*str>='0' && *str<='9')
               ret = ret*10 + (*str-'0');
            else break;
            str++;
        }
        if(flag > 0 && ret > ((1<<31)-1)) return (1<<31)-1;
        if(flag < 0 && ret > (((long long)1)<<31)) return 1<<31;
        return flag*ret;
    }
};