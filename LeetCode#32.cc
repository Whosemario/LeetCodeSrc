class Solution {
private:
    void dfs(int ind , vector<int>& cand, int target, int sum ,vector<int>& col, 
          vector<vector<int> >& res){
              if(sum==target){
                  vector<int> tmp;
                  for(int i=0;i<cand.size();i++)
                    if(col[i]){
                        for(int j=0;j<col[i];j++)
                            tmp.push_back(cand[i]);
                    }
                  res.push_back(tmp);
                  return ;
              }
              if(sum>target) return ;
              if(ind==cand.size()) return ;
              
              dfs(ind+1,cand,target,sum,col,res);
              while(sum<=target){
                  col[ind]++;
                  sum+=cand[ind];
                  dfs(ind+1,cand,target,sum,col,res);
              }
                col[ind]=0;
            return ;        
          }
          
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        sort(candidates.begin(),candidates.end());
        int size = candidates.size();
        if(size==0) return ret;
        vector<int> cand;
        cand.push_back(candidates[0]);
        for(int i=1;i<size;i++)
            if(candidates[i]!=candidates[i-1])
                cand.push_back(candidates[i]);
        size = cand.size();
        vector<int> col(size);
        for(int i=0;i<size;i++) col[i]=0;
        dfs(0,cand,target,0,col,ret);
        return ret;
    }
};