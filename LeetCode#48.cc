class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(n==0) return ret;
        
        for(int i=0;i<n;i++)
            ret.push_back(vector<int>(n,0));
            
        int cnt = 1;
        for(int i=0;i<(n+1)/2;i++)
            if(i==n-1-i) ret[i][i]=cnt++;
            else{
                for(int j=i;j<n-i;j++)
                    ret[i][j]=cnt++;
                for(int j=i+1;j<n-1-i;j++)
                    ret[j][n-1-i]=cnt++;
                for(int j=n-1-i;j>=i;j--)
                    ret[n-1-i][j]=cnt++;
                for(int j=n-2-i;j>i;j--)
                    ret[j][i] = cnt++;
            }
        
        return ret;
    }
};