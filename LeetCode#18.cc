class Solution {
private:
    void dfs(string str,int ind, string& digits, map<char,string>& table, vector<string>& ret){
        if(ind == digits.length()){
            ret.push_back(str);
            return;
        }
        
        if(digits[ind]=='1') dfs(str,ind+1,digits,table,ret);
        else{
            string& s = table[digits[ind]];
            for(int i=0;i<s.length();i++)
                dfs(str+s[i],ind+1,digits,table,ret);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        
        map<char,string> table;
        table['0']=" ";
        table['1']="";
        table['2']="abc";
        table['3']="def";
        table['4']="ghi";
        table['5']="jkl";
        table['6']="mno";
        table['7']="pqrs";
        table['8']="tuv";
        table['9']="wxyz";
        
    
        string s = "";
        
        dfs(s,0,digits,table,ret);
        
        return ret;
    }
};