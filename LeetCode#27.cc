class Solution {
private:
    void calcPi(char* pattern,vector<int>& pi){
        pi[0]=-1;
        for(int i=1;i<strlen(pattern);i++){
            int j = pi[i-1];
            while(j!=-1&&pattern[j+1]!=pattern[i])
                j=pi[j];
            if(pattern[j+1]==pattern[i])
                pi[i] = j+1;
            else
                pi[i]=-1;
        }
    }
    
    int find(char* src, char* pattern, vector<int>& pi){
        for(int i=0,j=-1;i<strlen(src);i++){
            while(j!=-1&&pattern[j+1]!=src[i])
                j=pi[j];
            if(pattern[j+1]==src[i]) j++;
            if(j==strlen(pattern)-1)
                return i-j;
        }
        return -1;
    }
    
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(haystack==NULL || needle==NULL) return NULL;
        if(strlen(needle)==0) return haystack;
        vector<int> pi(strlen(needle));
        calcPi(needle,pi);
        int offset = find(haystack,needle,pi);
        if(offset==-1) return NULL;
        else return haystack+offset;
        
    }
};