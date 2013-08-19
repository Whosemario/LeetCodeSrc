class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int size = num.size();
        
        vector<vector<int> > ret;
        if(size<4) return ret;
        
        sort(num.begin(),num.end());
        
        for(int a = 0; a <size;a++){
            if(a!=0 && num[a-1]==num[a]) continue;
            for(int b=a+1;b<size;b++){
                if(b!=a+1 && num[b-1]==num[b]) continue;
                int c=b+1,d=size-1;
                int tar = target - num[a] - num[b];
                while(c < d){
                    if(num[c]+num[d]==tar){
                        vector<int> tmp;
                        tmp.push_back(num[a]);
                        tmp.push_back(num[b]);
                        tmp.push_back(num[c]);
                        tmp.push_back(num[d]);
                        ret.push_back(tmp);
                        c++;
                        while(c<d && num[c]==num[c-1]) c++;
                    }
                    else if(num[c]+num[d] > tar) d--;
                    else c++;
                }
            }
        }
        
        return ret;
        
    }
};