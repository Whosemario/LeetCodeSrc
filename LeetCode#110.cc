class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ret;
        
        map<string,vector<string> > _hash;
        
        for(int i=0;i<strs.size();i++){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            _hash[tmp].push_back(strs[i]);
        }
        
        for(map<string,vector<string> >::iterator it = _hash.begin();
            it != _hash.end(); it++){
                vector<string>& vec = it->second;
                if(vec.size() > 1){
                    for(int i=0;i<vec.size();++i)
                        ret.push_back(vec[i]);
                }
            }
            
        return ret;
    }
};