class Solution {
private:
    void dfs(int x, int y,vector<vector<int> >& grid, vector<vector<int> >& dp){
        if(dp[x][y]!=-1) return ;
        
        if(x>0){
            dfs(x-1,y,grid,dp);
            if(dp[x][y]==-1 || dp[x][y]>grid[x][y]+dp[x-1][y])
                dp[x][y]=dp[x-1][y]+grid[x][y];
        }
        
        if(y>0){
            dfs(x,y-1,grid,dp);
            if(dp[x][y]==-1 || dp[x][y]>grid[x][y]+dp[x][y-1])
                dp[x][y]=dp[x][y-1]+grid[x][y];
        }
        return ;
    }
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = grid.size();
        if(N==0) return 0;
        int M = grid[0].size();
        if(M==0) return 0;
        
        vector<vector<int> > dp;
        for(int i=0;i<N;i++) dp.push_back(vector<int>(M,-1));
        dp[0][0]=grid[0][0];
        dfs(N-1,M-1,grid,dp);
        
        return dp[N-1][M-1];
    }
};