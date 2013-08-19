class Solution {
private:
    void dfs(int left, int right, vector<string>& ret, string res,int n){
        if(left==0 && right==0){
            ret.push_back(res);
            return ;
        }
        if(left>0) dfs(left-1,right+1,ret,res+'(',n);
        if(right >0) dfs(left,right-1,ret,res+')',n);
    }
public:
    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(n==0) return ret;
        dfs(n,0,ret,"",n);
        return ret;
    }
};