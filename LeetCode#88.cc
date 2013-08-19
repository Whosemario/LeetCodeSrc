class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = word2.length();
        int m = word1.length();
        
        vector<vector<int> > dp;
        for(int i=0;i<=n;i++) dp.push_back(vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++) dp[i][0]=i;
        for(int j=1;j<=m;j++) dp[0][j]=j;
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(word1[j-1]==word2[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = dp[i-1][j] < dp[i][j-1] ? dp[i-1][j]+1:dp[i][j-1]+1;
                    dp[i][j] = dp[i][j] < dp[i-1][j-1]+1 ? dp[i][j] : dp[i-1][j-1]+1;
                }
            }
            
        return dp[n][m];
    }
};