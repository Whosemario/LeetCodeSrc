class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(dict.size()<=1) return 0;
        if(dict.find(start)==dict.end() || dict.find(end)==dict.end()) return 0;
        
        vector<pair<string,int> > que;
        int head=0;
        
        set<string> _hash;
        
        que.push_back(make_pair(start,1));
        
        _hash.insert(start);
        
        while(head < que.size()){
            pair<string,int> item = que[head++];
            if(item.first==end) return item.second;
            
            for(int i=0;i<item.first.length();i++)
                for(int j=0;j<26;j++){
                    string t = item.first;
                    t[i] = (char)(j+'a');
                    if(dict.find(t)!=dict.end()&&_hash.find(t)==_hash.end()){
                        _hash.insert(t);
                        que.push_back(make_pair(t,item.second+1));
                    }
                }
        }
        
        return 0;
    }
};