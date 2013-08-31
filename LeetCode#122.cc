class Solution {
private:
    void dfs(int ind, bool flag, int remind,string ts,string& s, int k, vector<string>& ret)
    {
        if(ind==12){
            int num = 0;
            for(int i=0;i<ts.length();i++){
                if(ts[i]=='.'){
                    if(num>255) return ;
                    num=0;
                }
                else num = num*10 + (ts[i]-'0');
            }
            if(num>255) return ;
            ret.push_back(ts);
            return ;
        }
        if(k==s.length()) return ;
        if(ind == 3 || ind == 6 || ind == 9){
            ts += ".";
            flag = false;
        }
        if(ind%3==0){
            if(s[k]=='1' || s[k]=='2') 
                dfs(ind+1,true,remind,ts+s[k],s,k+1,ret);
            if(remind>0)
                dfs(ind+1,false,remind-1,ts,s,k,ret);
        }
        else if(ind%3==1){
            if(flag){
                if(s[k-1]=='1'){
                    dfs(ind+1,true,remind,ts+s[k],s,k+1,ret);
                }
                else{
                    if(s[k]<='5')
                        dfs(ind+1,true,remind,ts+s[k],s,k+1,ret);
                }
            }
            else{
                if(s[k]>='1' && s[k]<='9')
                    dfs(ind+1,true,remind,ts+s[k],s,k+1,ret);
                if(remind>0)
                    dfs(ind+1,false,remind-1,ts,s,k,ret);
            }
        }
        else{
                    dfs(ind+1,true,remind,ts+s[k],s,k+1,ret);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        if(s.length()<4 || s.length()>12) return ret;
            
        dfs(0,false,12-s.length(),"",s,0,ret);
        
        return ret;
    }
};