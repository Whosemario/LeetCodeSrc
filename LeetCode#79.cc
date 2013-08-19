class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = triangle.size();
        assert(size > 0);
        
        vector<int> dp(size,0);
        
        for(int i=0;i<size;i++) dp[i]=triangle[size-1][i];
        
        for(int i=size-2;i>=0;i--)
            for(int j=0;j<=i;j++)
                dp[j]= triangle[i][j] + (dp[j]<dp[j+1]?dp[j]:dp[j+1]);
                
        return dp[0];
    }
};