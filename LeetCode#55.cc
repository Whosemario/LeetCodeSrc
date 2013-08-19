class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string ret = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int c = 0;
        int i;
        for(i=0;i<a.length()&&i<b.length();i++){
            int t = c + (a[i]=='1') + (b[i]=='1');
            ret+=('0'+t%2);
            c=t/2;
        }
        
        while(i<a.length()){
            int t = c+(a[i]=='1');
            ret+=('0'+t%2);
            c=t/2;
            i++;
        
        }
        
        while(i<b.length()){
            int t= c+(b[i]=='1');
            ret+=('0'+t%2);
            c=t/2;
            i++;
        }
        
        if(c) ret+="1";
        
        reverse(ret.begin(),ret.end());
        
        return ret;
        
        
    }
};