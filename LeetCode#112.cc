class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()==0) return 0;
        int _min = num[0],_max = num[0];
        
        for(int i=1;i<num.size();++i){
            if(num[i]<_min) _min = num[i];
            if(num[i]>_max) _max = num[i];
        }
        
        map<int,int> _hash;
        
        for(int i=0;i<num.size();++i)
            _hash[num[i]-_min]=1;
            
        int ret = 0;
        
        for(int i=0;i<num.size();i++)
            if(_hash[num[i]-_min]==1){
                int cnt = 1;
                _hash[num[i]-_min]=2;
                //right
                for(int k = num[i]+1;k<=_max;++k)
                    if(_hash[k-_min]==1){
                        cnt++;
                        _hash[k-_min]=2;
                    }
                    else break;
                //left
                for(int k= num[i]-1;k>=_min;k--)
                    if(_hash[k-_min]==1){
                        cnt++;
                        _hash[k-_min]=2;
                    }
                    else break;
                if(cnt > ret) ret=cnt;
            }
        
        return ret;
    }
};