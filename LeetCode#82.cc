class Solution {
private:
    int n,m;
    void process(vector<vector<char> >& board,
                vector<vector<int> >& col,
                int x, int y){
        col[x][y]=1;
        int head = 0;
        vector<pair<int,int> > que;
        que.push_back(make_pair(x,y));
        bool flag = false;
        while(head < que.size()){
            pair<int,int>& pos = que[head++];
            int i = pos.first;
            int j = pos.second;
            if(i==0 || i==n-1 || j==0 || j==m-1) flag=true;
            //up
            if(i>0 && board[i-1][j]=='O' && col[i-1][j]==0){
                col[i-1][j]=1;
                que.push_back(make_pair(i-1,j));
            }
            //down
            if(i<n-1 && board[i+1][j]=='O' && col[i+1][j]==0){
                col[i+1][j]=1;
                que.push_back(make_pair(i+1,j));
            }
            //left
            if(j>0 && board[i][j-1]=='O' && col[i][j-1]==0){
                col[i][j-1]=1;
                que.push_back(make_pair(i,j-1));
            }
            //right
            if(j<m-1 && board[i][j+1]=='O' && col[i][j+1]==0){
                col[i][j+1]=1;
                que.push_back(make_pair(i,j+1));
            }
            
        }
        
        if(!flag){
            for(int i=0;i<que.size();i++)
                board[que[i].first][que[i].second] = 'X';
        }
    }
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = board.size();
        if(n==0) return ;
        m = board[0].size();
        if(m==0) return ;
        
        vector<vector<int> > col;
        for(int i=0;i<n;i++) col.push_back(vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='O' && col[i][j]==0){
                    process(board,col,i,j);
                }
                
        return;
    }
};