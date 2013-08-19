class Solution {
private:
    bool isOK(vector<int>& col, int x, int y){
        for(int i=0;i<col.size();i++)
            if(col[i]!=-1 && abs(x-col[i])==abs(y-i))
                return false;
        return true;
    }
    
    void dfs(int ind, int n, vector<int>& col, int& res){
        if(ind == n){
            res++;
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
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return 0;
        
        vector<int> col(n,-1);
        
        int ret=0;
        
        dfs(0,n,col,ret);
        
        return ret;
    }
};
