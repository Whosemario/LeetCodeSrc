class Solution{
public:
bool isMatch(const char *s, const char *p) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if(!s && !p) return true;

    const char *star_p=NULL,*star_s=NULL;

    while(*s)
    {
        if(*p == '?' || *p == *s)
        {
            ++p,++s;
        }else if(*p == '*')
        {
            //skip all continuous '*'
            while(*p == '*') ++p;

            if(!*p) return true; //if end with '*', its match.

            star_p = p; //store '*' pos for string and pattern
            star_s = s;
        }else if((!*p || *p != *s)  && star_p)
        {
            s = ++star_s; //skip non-match char of string, regard it matched in '*'
            p = star_p; //pattern backtrace to later char of '*'
        }else
            return false;
    }

    //check if later part of p are all '*'
    while(*p)
        if(*p++ != '*')
            return false;

    return true;
}
};