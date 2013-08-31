class Solution {
private:
    void gen(string str, string end,vector<string> tmp,
        map<string,vector<string> >& prev, vector<vector<string> >& res){
            tmp.push_back(str);
            if(str==end){
                reverse(tmp.begin(),tmp.end());
                res.push_back(tmp);
                return;
            }
            
            vector<string>& vec = prev[str];
            
            for(int i=0;i<vec.size();i++)
                gen(vec[i],end,tmp,prev,res);
        }
        
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        if(dict.size() <= 1) return ret;
        if(dict.find(start)==dict.end() || dict.find(end)==dict.end()) return ret;
        
        vector<pair<string,int> > que;
        int head = 0;
        que.push_back(make_pair(start,1));
        
        map<string,int> _hash;
        map<string,vector<string> > prev;
        map<string,vector<string> > li;
        for(unordered_set<string>::iterator it = dict.begin();
            it!=dict.end();++it){
                const string& from = *it;
                vector<string>& vec = li[from];
                for(int i=0;i<start.length();++i){
                    string t = from;
                    for(int j=0;j<26;j++){
                        t[i] = (char)(j+'a');
                        if(t!=from && dict.find(t)!=dict.end())
                            vec.push_back(t);  
                    }
                }
            }
        
        while(head < que.size()){
            if(que[head].first == end){
                break;
            }
            
            _hash[que[head].first] = que[head].second;
            vector<string>& vec = li[que[head].first];
            for(int i=0;i<vec.size();i++){
                    string& t = vec[i];
                    if(_hash.find(t)==_hash.end() || que[head].second+1 == _hash[t]){
                                
                                if(_hash.find(t)==_hash.end())
                                    que.push_back(make_pair(t,que[head].second+1));
                                _hash[t] = que[head].second+1;
                                prev[t].push_back(que[head].first);
                    }
            }
            
            head++;
        }
        
        gen(end,start,vector<string>(),prev,ret);
        
        return ret;
    }
};