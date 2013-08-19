class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        int j=0;
        for(int i=0;i<len;i++){
            if(s[i]>='A'&&s[i]<='Z') s[j++]=(s[i]-'A')+'a';
            else if(s[i]>='a'&&s[i]<='z') s[j++]=s[i];
            else if(s[i]>='0'&&s[i]<='9') s[j++]=s[i];
        }
        
        if(j==0) return true;
        
        for(int i=0;i<j/2;i++)
            if(s[i]!=s[j-1-i]) return false;
            
        return true;
    }
};