class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = num.size();
        if(size<=1) return ;
        int _max = num[size-1];
        for(int i=size-2;i>=0;i--){
            if(num[i]>=_max){
                _max = num[i];
            }
            else{
                int ind = -1;
                for(int j=i+1;j<size;j++)
                    if(num[j]>num[i]&&(ind==-1 || num[ind]>num[j]))
                        ind = j;
                int tmp = num[ind];
                num[ind] = num[i];
                num[i] = tmp;
                sort(num.begin()+i+1,num.end());
                return ;
            }
        }
        sort(num.begin(),num.end());
        return ;
    }
};