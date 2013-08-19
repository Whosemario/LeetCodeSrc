class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len==0) return 0;
        vector<int> dp(len+1);
        dp[len]=1;
        if(s[len-1]=='0') dp[len-1]=0;
        else dp[len-1]=1;
        
        for(int i=len-2;i>=0;i--)
            if(s[i]=='0') dp[i]=0;
            else if(s[i]=='1'){
                dp[i]=dp[i+1]+dp[i+2];
            }
            else if(s[i]=='2'){
                dp[i]=dp[i+1];
                if(s[i+1]>='0'&&s[i+1]<='6') dp[i]+=dp[i+2];
            }
            else dp[i]=dp[i+1];
            
        return dp[0];
    }
};