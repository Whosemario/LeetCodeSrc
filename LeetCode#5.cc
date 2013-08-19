#include<string.h>
#include<string>

int dp[1002][1002];
    
class Solution {
private:

    
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = s.length();
        if(N==0) return "";
        
        memset(dp,-1,sizeof(dp));
        
        int left=0,right = 0;
        for(int i=0;i<N;i++) dp[i][i]=1;
        for(int i=0;i<N-1;i++)
            if(s[i]==s[i+1]){
                left=i;right=i+1;
                dp[i][i+1]=2;
            }
        
        for(int k=3;k<=N;k++)
            for(int i=0;i+k-1<N;i++)
                if(s[i]==s[i+k-1]&&dp[i+1][i+k-2]!=-1){
                    dp[i][i+k-1]=k;
                    if(right-left+1 < k){
                        left = i;
                        right = i+k-1;
                    }
                }
        
        return s.substr(left,right-left+1);
    }
};