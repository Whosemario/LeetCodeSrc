class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len==0) return true;
        vector<char> _stack(len);
        int top = 0;
        for(int i=0;i<len;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') _stack[top++]=s[i];
            else if(top > 0){
                if(s[i]==')' && _stack[top-1]=='(') top--;
                else if(s[i]==']' && _stack[top-1]=='[') top--;
                else if(s[i]=='}' && _stack[top-1]=='{') top--;
                else return false;
            }
            else return false;
        }
        if(top) return false;
        return true;
    }
};