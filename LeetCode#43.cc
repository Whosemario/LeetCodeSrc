class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> ret;
        
        int N = matrix.size();
        
        if(N==0) return ret;
        
        int M = matrix[0].size();
        
        for(int i=0;i<(N+1)/2;i++)
            if(i<=M-1-i){
                for(int j=i;j<M-i;j++)
                    ret.push_back(matrix[i][j]);
                if(i<N-1-i){
                    for(int j=i+1;j<N-1-i;j++)
                        ret.push_back(matrix[j][M-1-i]);
                    for(int j=M-1-i;j>=i;j--)
                        ret.push_back(matrix[N-1-i][j]);
                    if(i<M-1-i)
                        for(int j=N-i-2;j>i;j--)
                            ret.push_back(matrix[j][i]);
                }
            }
            
        return ret;
    }
};