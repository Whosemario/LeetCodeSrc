class Solution {
public:
    bool isScramble(string s1, string s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s1==s2) return true;
    if(s1.length()!=s2.length()) return false;
   
    int N = s1.length();
    vector<vector<vector<bool> > > dp(N,vector<vector<bool> >(N,vector<bool>(N,false)));
   
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++){
        dp[i][j][0] = true;
        dp[i][j][1] = s1[i]==s2[j];
      }
     
    for(int i=s1.length()-1;i>=0;i--)
      for(int j=s2.length()-1;j>=0;j--){
        int n = min(N-i,N-j);
        for(int k = 2;k<=n;k++){
          for(int m=1;m<k;m++){
            dp[i][j][k] = (dp[i][j][m]&&dp[i+m][j+m][k-m])||(dp[i][j+k-m][m]&&dp[i+m][j][k-m]);
            if(dp[i][j][k]) break;
          }
        }
      }
     
    return dp[0][0][s1.length()];
    }
};

