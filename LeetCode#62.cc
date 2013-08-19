class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lenS = S.length();
        int lenT = T.length();
        if(lenS < lenT) return "";
        if(lenS==0 || lenT==0) return "";
        
        vector<int> _hash(128,0);
        for(int i=0;i<lenT;i++)
            _hash[T[i]]++;
        int cnt = 0;
        for(int i=0;i<128;i++)
            if(_hash[i]) ++cnt;
            
        vector<int> tmp(128,0);
        int tmpCnt = 0;
        int head =0, tail = 0;
        
        int left=-1,right=-1;
        
        for(;head<=tail&&tail<lenS;){
            if(tmpCnt==cnt){
                if(left==-1 || tail-head < right-left){
                    left = head;
                    right = tail;
                }
                if(_hash[S[head]]){
                    tmp[S[head]]--;
                    if(tmp[S[head]] < _hash[S[head]])
                        tmpCnt--;
                }
                head++;
            }
            else{
                if(_hash[S[tail]]){
                    tmp[S[tail]]++;
                    if(tmp[S[tail]]==_hash[S[tail]])
                        tmpCnt++;
                }
                tail++;
            }
        }
        
        while(head<tail){
            if(tmpCnt==cnt){
                if(left==-1 || tail-head < right-left){
                    left = head;
                    right = tail;
                }
                if(_hash[S[head]]){
                    tmp[S[head]]--;
                    if(tmp[S[head]] +1 ==  _hash[S[head]])
                        tmpCnt--;
                }
                head++;
            }
            else break;
        }
        
        if(left == -1) return "";
        else return S.substr(left,right-left);
    }
};