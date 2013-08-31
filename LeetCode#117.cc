class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(S.length()==0 || T.length()==0) return 0;
        vector<vector<int> > dp;
        for(int i=0;i<T.length();i++)
            dp.push_back(vector<int>(S.length(),0));
            
        vector<int> sum(S.length(),0);
        
        for(int i=0;i<S.length();i++)
            if(T[0]==S[i]) dp[0][i]=1;
            
        for(int i=1;i<T.length();++i){
            sum[0]=dp[i-1][0];
            for(int j=1;j<S.length();j++)
                sum[j]=sum[j-1]+dp[i-1][j];
            
            
            for(int j=i;j<S.length();j++)
                if(S[j]==T[i]) dp[i][j]=sum[j-1];
        }
        
        int ret = 0;
        for(int j = T.length()-1;j<S.length();j++)
            ret+=dp[T.length()-1][j];
            
        return ret;
    }
};