class Solution {
private:
    void dfs(int ind, vector<int>& num, int target, int sum,
    vector<int>& col, vector<vector<int> >& res){
        if(sum==target){
            vector<int> tmp;
            for(int i=0;i<col.size();i++)
                if(col[i]) tmp.push_back(num[i]);
            res.push_back(tmp);
        }
        if(sum > target) return ;
        for(int i=ind;i<num.size();i++)
            if(i==ind || num[i]!=num[i-1]){
                col[i]=1;
                dfs(i+1,num,target,sum+num[i],col,res);
                col[i]=0;
            }
        return;
    }
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ret;
        if(num.size()==0) return ret;
        sort(num.begin(),num.end());
        vector<int> col(num.size());
        for(int i=0;i<col.size();i++)
            col[i]=0;
        dfs(0,num,target,0,col,ret);
        return ret;
    }
};