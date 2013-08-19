class Solution {
private:
    bool isOK(vector<int>& col, int x, int y){
        for(int i=0;i<col.size();i++)
            if(col[i]!=-1 && abs(x-col[i])==abs(y-i))
                return false;
        return true;
    }
    
    void dfs(int ind, int n, vector<int>& col, vector<vector<string> >& res){
        if(ind == n){
            vector<string> tmp;
            for(int i=0;i<n;i++)
                tmp.push_back(string(n,'.'));
            for(int i=0;i<n;i++)
                tmp[col[i]][i]='Q';
            res.push_back(tmp);
            return ;
        }
        for(int i=0;i<n;i++)
            if(col[i]==-1 && isOK(col,ind,i)){
                col[i]=ind;
                dfs(ind+1,n,col,res);
                col[i]=-1;
            }
    }
    
public:
    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        if(n==0) return ret;
        
        vector<int> col(n,-1);
        
        dfs(0,n,col,ret);
        
        return ret;
    }
};