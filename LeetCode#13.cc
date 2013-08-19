class Solution {
public:
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.length();
        if(len<=0) return 0;
        int ret = 0;
        int i =0;
        while(i<len){
            if(s[i]=='M') ret+=1000;
            else if(s[i]=='D') ret+=500;
            else if(s[i]=='C'){
                if(i!=len-1&&s[i+1]=='M') {ret+=900;i++;}
                else if(i!=len-1&&s[i+1]=='D'){ret+=400;i++;}
                else ret+=100;
            }
            else if(s[i]=='L') ret+=50;
            else if(s[i]=='X'){
                if(i!=len-1&&s[i+1]=='L'){ret+=40;i++;}
                else if(i!=len-1&&s[i+1]=='C'){ret+=90;i++;}
                else ret+=10;
            }
            else if(s[i]=='V') ret+=5;
            else if(s[i]=='I'){
                if(i!=len-1&&s[i+1]=='V'){ret+=4;i++;}
                else if(i!=len-1&&s[i+1]=='X'){ret+=9;i++;}
                else ret+=1;
            }
            i++;
        }
        
        return ret;
    }
};