class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(*p=='\0') return *s=='\0';
        if(*p=='*') return isMatch(s,p+1);
        if(*(p+1)!='*')
            return (*p==*s || (*p=='.' && *s!='\0')) && isMatch(s+1,p+1);
            
        while(*p==*s || (*p=='.' && *s!='\0')){
            if(isMatch(s,p+2)) return true;
            s++;
        }
        
        return isMatch(s,p+2);
    }
};