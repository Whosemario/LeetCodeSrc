class Solution {
public:
    int minCut(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len <= 1) return 0;
        vector<vector<int> > dp;
        for(int i=0;i<len;i++)
            dp.push_back(vector<int>(len,1));
                
        for(int k=1;k<len;k++)
            for(int i=0;i+k<len;i++)
                if(k==1){
                    if(s[i]==s[i+k]) dp[i][i+k]=1;
                    else dp[i][i+k]=0;
                }
                else{
                    if(s[i]==s[i+k]&&dp[i+1][i+k-1]==1) dp[i][i+k]=1;
                    else dp[i][i+k]=0;
                }
                
        vector<int> col(len,-1);
        for(int i=0;i<len;i++)
            if(dp[0][i]==1) col[i]=0;
            else{
                for(int j=0;j<i;j++)
                    if(col[j]!=-1&&dp[j+1][i]==1)
                        if(col[i]==-1 || col[i] > col[j]+1) col[i]=col[j]+1;
            }
        return col[len-1];
    }
};