class Solution {
private:

    int dfs(int n, vector<int>& dp){
        if(dp[n]!=-1) return dp[n];
        dp[n]=0;
        
        for(int i=1;i<=n;i++)
            dp[n]+=dfs(i-1,dp)*dfs(n-i,dp);
        
        return dp[n];
    }
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        
        vector<int> dp(n+1,-1);
        dp[0] = dp[1] = 1;
        dp[2] = 2;
        
        return dfs(n,dp);
        
    }
};