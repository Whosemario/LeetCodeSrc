class Solution {
private:
    int n;
    int m;
    bool dfs(int x,int y,int cnt,vector<vector<int> > &col,
            vector<vector<char> > &board,string& word){
                if(cnt==word.length()) return true;
                if(x<0||x>=n || y <0 || y>=m) return false;
                if(col[x][y]==1 || word[cnt]!=board[x][y]) return false;
                
                col[x][y]=1;
                bool ret = false;
                // up
                ret = dfs(x-1,y,cnt+1,col,board,word);
                if(ret) return true;
                
                //down
                ret = dfs(x+1,y,cnt+1,col,board,word);
                if(ret) return true;
                
                //left
                ret = dfs(x,y-1,cnt+1,col,board,word);
                if(ret) return true;
                
                //right
                ret=dfs(x,y+1,cnt+1,col,board,word);
                if(ret) return true;
                
                col[x][y]=0;
                return false;
            }
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = board.size();
        if(n==0) return false;
        m = board[0].size();
        if(m==0) return false;
        
        vector<vector<int> > col;
        for(int i=0;i<n;i++) col.push_back(vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                bool ret = dfs(i,j,0,col,board,word);
                if(ret) return true;
            }
            
        return false;
    }
};