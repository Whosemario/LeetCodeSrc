class Solution {
private:
    int dfs(int x,int y,vector<vector<int> > &obs, vector<vector<int> >& dp){
        if(obs[x][y]==1) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int ret=0;
        if(x>0) ret+=dfs(x-1,y,obs,dp);
        if(y>0) ret+=dfs(x,y-1,obs,dp);
        dp[x][y]=ret;
        return ret;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obs.size();
        if(m==0) return 0;
        int n = obs[0].size();
        if(n==0) return 0;
        
        if(obs[0][0]==1) return 0;
        
        vector<vector<int> > dp;
        for(int i=0;i<m;i++) dp.push_back(vector<int>(n,-1));
        dp[0][0]=1;
        
        return dfs(m-1,n-1,obs,dp);
    }
};