class Solution {
private:
    void gen(int n , vector<int>& res){
        int num = 1<<n;
        for(int i=num-1;i>=0;i--)
            res.push_back(res[i]+num);
    }
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(n==0){
            ret.push_back(0);
            return ret;
        }
        ret.push_back(0);
        ret.push_back(1);
        for(int i=1;i<n;i++)
            gen(i,ret);
        return ret;
    }
};