class Solution {
private:
    bool dfs(vector<vector<char> >& board,
            vector<int>& row,vector<int>& col,
            vector<int>& blk, int ind){
                if(ind==81) return true;
                int i = ind/9;
                int j = ind%9;
                
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if((row[i]&(1<<k))==0 &&
                            (col[j]&(1<<k))==0 && 
                            (blk[i/3*3+j/3]&(1<<k))==0){
                                row[i]|=(1<<k);
                                col[j]|=(1<<k);
                                blk[i/3*3+j/3]|=(1<<k);
                                board[i][j]=(char)('0'+k);
                                bool ret = dfs(board,row,col,blk,ind+1);
                                if(ret) return true;
                                
                                board[i][j]='.';
                                
                                row[i]&=~(1<<k);
                                col[j]&=~(1<<k);
                                blk[i/3*3+j/3]&=~(1<<k);
                            }
                    }
                }
                else return dfs(board,row,col,blk,ind+1);
            
                return false;
            }
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> row(9,0);
        vector<int> col(9,0);
        vector<int> blk(9,0);
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.'){
                    int k = board[i][j]-'0';
                    row[i]|=(1<<k);
                    col[j]|=(1<<k);
                    blk[i/3*3+j/3]|=(1<<k);
                    //board[i][j]=(char)('0'+k);
                }
        dfs(board,row,col,blk,0);
    }
};