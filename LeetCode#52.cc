class Solution {
private:

    int dfs(int x,int y, vector<vector<int> >& dp){
        if(dp[x][y]!=-1) return dp[x][y];
        int ret = 0;
        if(x>0) ret+=dfs(x-1,y,dp);
        if(y>0) ret+=dfs(x,y-1,dp);
        dp[x][y]=ret;
        return ret;
    }
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(m==0 || n==0) return 0;
        vector<vector<int> > dp;
        for(int i=0;i<m;i++) dp.push_back(vector<int>(n,-1));
        dp[0][0]=1;
        dfs(m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};