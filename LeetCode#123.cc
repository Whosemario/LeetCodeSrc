class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> vec;
        string str = "";
        
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
                if(str!="") vec.push_back(str);
                str="";
            }
            else str+=path[i];
        }
        if(str!="") vec.push_back(str);
        
        int ind = 0;
        for(int i=0;i<vec.size();i++){
            if(vec[i]==".."){
                if(ind>0) --ind;
            }
            else if(vec[i]!="."){
                vec[ind++]=vec[i];
            }
        }
        
        if(ind==0) return "/";
        else{
            string ret="";
            for(int i=0;i<ind;i++)
                ret += "/"+vec[i];
            return ret;
        }
    }
};