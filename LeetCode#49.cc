class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> pi(n+1,0);
        pi[1]=pi[0]=1;
        for(int i=2;i<=n;i++) pi[i]=i*pi[i-1];
        
        int pre = 0;
        string ret = "";
        vector<int> col(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                if(col[j]==0){
                    if(pre+pi[n-1-i]>=k){
                        col[j]=1;
                        ret+='1'+j;
                        break;
                    }
                    else{
                        pre+=pi[n-1-i];
                    }
                }
        }
        
        return ret;
        
    }
};