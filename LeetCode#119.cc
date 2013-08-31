class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ind = 0;
        vector<string> ret;
        vector<string> vec;
        int len = 0;
        while(ind < words.size()){
            if(len + words[ind].length() + vec.size() <= L){
                vec.push_back(words[ind]);
                len+=words[ind].length();
            }
            else{
                if(vec.size()==1){
                    ret.push_back(vec[0]+string(L-vec[0].length(),' '));
                }
                else{
                    string str = "";
                    int space = L;
                    for(int i=0;i<vec.size();i++)
                        space -= vec[i].length();
                    int num = vec.size()-1;
                    str+=vec[0];
                    for(int i=1;i<vec.size();i++){
                        str+=string(space/num,' ')+(space%num>=i?" ":"");
                        str+=vec[i];
                    }
                    ret.push_back(str);
                }
                vec.clear();
                len = 0;
                ind--;
            }
            ind++;
        }
        
        string str = vec[0];
        for(int i=1;i<vec.size();i++)
            str+=" "+vec[i];
        str+=string(L-str.length(),' ');
        ret.push_back(str);
        
        return ret;
    }
};