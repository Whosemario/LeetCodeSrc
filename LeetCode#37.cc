class Solution {
private:
    void dfs(int ind, vector<int>& num, vector<int>& col, vector<int>& tmp, 
        vector<vector<int> >& ret){
            if(ind==num.size()){
                vector<int> tt = tmp;
                ret.push_back(tt);
                return ;
            }
            
            for(int i=0;i<num.size();i++)
                if(col[i]==0){
                    col[i]=1;
                    tmp[ind]=num[i];
                    dfs(ind+1,num,col,tmp,ret);
                    col[i]=0;
                }
            return ;
        }
public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> col(num.size());
        vector<int> tmp(num.size());
        vector<vector<int> > ret;
        if(num.size()==0) return ret;
        
        for(int i=0;i<num.size();i++)
            col[i]=0;
        
        dfs(0,num,col,tmp,ret);
        
        return ret;
    }
};