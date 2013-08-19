class Solution {
public:
    void rotate(vector<vector<int> > &mat) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = mat.size();
        if(N<=1) return ;
        
        for(int i=0;i<N/2;i++)
            for(int j=i;j<N-1-i;j++){
                int tmp = mat[i][j];
                mat[i][j]=mat[N-1-j][i];
                mat[N-1-j][i]=mat[N-1-i][N-1-j];
                mat[N-1-i][N-1-j]=mat[j][N-1-i];
                mat[j][N-1-i]=tmp;
            }
        
        return ;
    }
};