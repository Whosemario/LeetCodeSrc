class Solution {
public:
    void setZeroes(vector<vector<int> > &mat) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = mat.size();
        if(n==0) return ;
        int m = mat[0].size();
        if(m==0) return ;
        
        bool row = false,col=false;
        for(int j=0;j<m;j++)
            if(mat[0][j]==0){row=true;break;}
        
        for(int i=0;i<n;i++)
            if(mat[i][0]==0){col=true;break;}
            
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==0){
                    mat[i][0]=mat[0][j]=0;
                }
                
        for(int i=1;i<n;i++)
            if(mat[i][0]==0) 
                for(int j=0;j<m;j++)
                    mat[i][j]=0;
                    
        for(int j=1;j<m;j++)
            if(mat[0][j]==0)
                for(int i=0;i<n;i++)
                    mat[i][j]=0;
                    
        if(row)
            for(int j=0;j<m;j++)
                mat[0][j]=0;
        
        if(col)
            for(int i=0;i<n;i++)
                mat[i][0]=0;
                
        return ;
    }
};