class Solution {
public:
    int maximalRectangle(vector<vector<char> > &mat) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = mat.size();
        if(N==0) return 0;
        int M = mat[0].size();
        if(M==0) return 0;
        
        vector<vector<int> > sum;
        for(int i=0;i<N;i++)
            sum.push_back(vector<int>(M,0));
            
        for(int i=0;i<N;i++){
            sum[i][M-1] = mat[i][M-1]=='1' ? 1:0;
            for(int j=M-2;j>=0;j--)
                if(mat[i][j]=='0') sum[i][j]=0;
                else sum[i][j] = sum[i][j+1]+1;
        }
        
        int ret = 0;
        for(int k=0;k<M;k++){
            for(int i=0;i<N;i++){
                int _min = sum[i][k];
                if(_min==0) continue;
                for(int j=i;j<N;j++){
                    _min = min(sum[j][k],_min);
                    if(_min==0) break;
                    if((j-i+1)*_min > ret)
                        ret = (j-i+1)*_min;
                }
            }
        }
        
        return ret;
    }
};