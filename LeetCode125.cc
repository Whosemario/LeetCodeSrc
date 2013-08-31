class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> row(9,0);
        vector<int> col(9,0);
        vector<int> blk(9,0);
        
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int k = board[i][j]-'0';
                if((row[i]&(1<<k)) || (col[j]&(1<<k)) || 
                    (blk[j/3+i/3*3]&(1<<k))) return false;
                
                row[i] |= 1<<k;
                col[j] |= 1<<k;
                blk[j/3+i/3*3] |= 1<<k;
            }
        return true;
    }
};