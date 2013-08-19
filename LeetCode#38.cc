class Solution {
private:
    void dfs(int ind, vector<int>& num, vector<int>& col,
        vector<int>& tmp, vector<vector<int> >& res){
            if(ind==num.size()){
                vector<int> tt = tmp;
                res.push_back(tt);
            }
            
            int flag = 0;
            int pre;
            for(int i=0;i<num.size();i++)
                if(col[i]==0 && (flag==0 || num[i]!=pre)){
                    flag = 1;
                    col[i]=1;
                    tmp[ind]=num[i];
                    pre = num[i];
                    dfs(ind+1,num,col,tmp,res);
                    col[i]=0;
                }
            return ;
        }
        
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(num.size()==0) return ret;
        vector<int> col(num.size());
        vector<int> tmp(num.size());
        
        sort(num.begin(),num.end());
        
        for(int i=0;i<num.size();i++) col[i]=0;
        
        dfs(0,num,col,tmp,ret);
        
        return ret;
    }
};