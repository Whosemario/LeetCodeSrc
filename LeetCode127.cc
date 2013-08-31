class Solution {
private:
  template<typename T>
  string ToString(T val){
    ostringstream scout;
    scout << val;
    return scout.str();
  }
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==1) return "1";
    string ret = "1";
    for(int i=1;i<n;i++){
      int cnt = 1;
      string tmp = "";
      for(int j=1;j<ret.length();j++)
        if(ret[j]==ret[j-1]) cnt++;
        else{
          tmp += ToString(cnt) + ret[j-1];
          cnt=1;
        }
      tmp += ToString(cnt)+ret[ret.length()-1];
      ret=tmp;
    }
    return ret;
    }
};