class Solution {
private:
    bool dfs(int x, int y, vector<vector<int> >& dp,
            string& s1, string& s2, string& s3){
                if(x==s1.length() && y==s2.length()) return true;
                if(dp[x][y]!=-1) return dp[x][y];
                if(x<s1.length() && s1[x]==s3[x+y]){
                    bool ret = dfs(x+1,y,dp,s1,s2,s3);
                    if(ret){
                        dp[x][y]=1;
                        return true;
                    }
                }
                if(y<s2.length() && s2[y]==s3[x+y]){
                    bool ret = dfs(x,y+1,dp,s1,s2,s3);
                    if(ret){
                        dp[x][y]=1;
                        return true;
                    }
                }
                
                dp[x][y]=0;
                return false;
            }
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s1.length()+s2.length() != s3.length()) return false;
        int l1 = s1.length();
        int l2 = s2.length();
        if(l1==0) return s2==s3;
        if(l2==0) return s1==s3;
        
        vector<vector<int> > dp;
        for(int i=0;i<=l1;i++)
            dp.push_back(vector<int>(l2+1,-1));
            
        return dfs(0,0,dp,s1,s2,s3);
    }
};