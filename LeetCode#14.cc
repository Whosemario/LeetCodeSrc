class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = strs.size();
        if(size==0) return "";
        if(size==1) return strs[0];
        int tail = strs[0].length();
        for(int i=1;i<size;i++){
            int j;
            for(j=0;j<strs[i].length()&&j<tail+1;j++)
                if(strs[0][j]!=strs[i][j]) break;
            if(j-1<tail) tail=j-1;
        }
        return strs[0].substr(0,tail+1);
    }
};