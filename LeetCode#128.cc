class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(L.size()==0) return ret;
        
        map<string,int> need;
        for(int i=0;i<L.size();i++)
            ++need[L[i]];
            
        int N = L.size();
        int len = L[0].length();
        
        for(int i=0;i<len;i++){
            int begin = i;
            int cnt = 0;
            map<string,int> sub;
            
            for(int j=begin;j<=(int)S.length()-len;j+=len){
                string w = S.substr(j,len);
                if(need.find(w)==need.end()){
                    sub.clear();
                    cnt=0;
                    begin = j+len;
                }
                else{
                    ++sub[w];
                    if(sub[w]<=need[w]) cnt++;
                    else{
                        while(true){
                            string t = S.substr(begin,len);
                            --sub[t];
                            begin += len;
                            if(sub[t]<need[t]) cnt--;
                            else break;
                        }
                    }
                    
                    if(cnt==N) ret.push_back(begin);
                }
            }
        }
        
        sort(ret.begin(),ret.end());
        
        return ret;
    }
};