class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        vector<int> sta(len);
        int top = 0;
        
        int left=0;
        int ret=0;
        for(int i=0;i<len;i++)
            if(s[i]=='(') sta[top++]=i;
            else{
                if(top==0) left = i+1;
                else{
                    top--;
                    if(top==0) ret = max(ret,i-left+1);
                    else ret = max(ret,i-sta[top-1]);
                }
            }
            
        return ret;
    }
};