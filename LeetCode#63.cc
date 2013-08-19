class Solution {
private:
    
    void dfs(int ind, int cnt, int n, int k,vector<int>& tmp, vector<vector<int> >& res){
        if(cnt==k){
            res.push_back(tmp);
            return ;
        }
        
        for(int i=ind;i<=n;i++){
            tmp[cnt]=i;
            dfs(i+1,cnt+1,n,k,tmp,res);
        }
    }
public:
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(k>n) return ret;
        if(k==0){
            ret.push_back(vector<int>());
            return ret;
        }
        
        vector<int> tmp(k,0);
        
        dfs(1,0,n,k,tmp,ret);
        
        return ret;
    }
};