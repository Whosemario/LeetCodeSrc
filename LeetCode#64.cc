class Solution {
private:
    
    void dfs(int ind,int cnt,int size,int k,vector<int>& S,
    vector<int>& tmp,vector<vector<int> >& res){
        if(cnt==k){
            res.push_back(tmp);
            return ;
        }
        
        for(int i=ind;i<size;i++){
            if(i==ind || S[i]!=S[i-1]){
                tmp[cnt]=S[i];
                dfs(i+1,cnt+1,size,k,S,tmp,res);
            }
        }
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        ret.push_back(vector<int>());
        int size = S.size();
        if(size==0) return ret;
        
        sort(S.begin(),S.end());
        for(int i=1;i<=size;i++){
           vector<int> tmp(i,0);
           dfs(0,0,size,i,S,tmp,ret);
        }
        
        return ret;
            
    }
};