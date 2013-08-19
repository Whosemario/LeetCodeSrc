#include<string.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int cnt[150];
        memset(cnt,0,sizeof(cnt));
        
        int ret = 0;
        int tail = 0, head = 0;
        
        int len = s.length();
        
        while(head < len){
            if(cnt[(int)s[head]]==0){
                cnt[(int)s[head]] = 1;
                if(ret < head-tail+1)
                    ret = head - tail + 1;
                head++;
            }
            else{
                while(s[tail]!=s[head]) {
                    cnt[(int)s[tail]] = 0;
                    tail++;
                }
                tail++;
                if(ret < head-tail+1) 
                   ret = head-tail+1;
                head++;
            }
        }
        
        return ret;
    }
};