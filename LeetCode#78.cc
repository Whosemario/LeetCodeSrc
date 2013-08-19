class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> ret (rowIndex+1,1);
        
        if(rowIndex < 2) return ret;
        
        int pre = 0;
        for(int i = 3;i<=rowIndex+1;i++){
            pre = 1;
            for(int j=1;j<i-1;j++){
                int tmp = ret[j];
                ret[j] = pre+ret[j];
                pre = tmp;
            }
        }
        
        return ret;
    }
};