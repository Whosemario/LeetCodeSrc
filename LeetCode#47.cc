class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(s);
        int len = strlen(s);
        if(len == 0) return 0;
        int i = len-1;
        while(i>=0&&s[i]==' ') i--;
        int ret = 0;
        while(i>=0&&s[i]!=' '){ret++;i--;}
        
        return ret;
    }
};