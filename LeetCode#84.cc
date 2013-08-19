class Solution {
private:
    void dfs(int ind, string& s, vector<vector<bool> >& dp,
        vector<vector<string> >& res,vector<string> val){
            if(ind==s.length()){
                if(val.size()>0) res.push_back(val);
                return ;
            }
            for(int i=ind;i<s.length();i++)
                if(dp[ind][i]){
                    vector<string> tmp = val;
                    tmp.push_back(s.substr(ind,i-ind+1));
                    dfs(i+1,s,dp,res,tmp);
                }
        }
public:
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        vector<vector<string> > ret;
        if(len==0) return ret;
        
        vector<vector<bool> > dp;
        for(int i=0;i<len;i++) dp.push_back(vector<bool>(len,true));
        
        for(int k=1;k<len;k++)
            for(int i=0;i+k<len;i++)
                if(k==1){
                    if(s[i]!=s[i+k]) dp[i][i+k]=false; 
                }
                else{
                    if(s[i]!=s[i+k] || dp[i+1][i+k-1]==false) dp[i][i+k]=false;
                }
                
        dfs(0,s,dp,ret,vector<string>());
        
        return ret;
    }
};