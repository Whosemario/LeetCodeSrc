#define _abs(x) ((x)<0?-(x):(x))


int find(int low, int high,int target,vector<int>& num){
    
    int l = low,h = high;
    
    if(low > high) return -1;
    
    
    while(low<=high){
        int mid = (low+high)/2;
        if(num[mid]==target){return mid;}
        else if(target<num[mid]) high = mid-1;
        else low = mid+1;
    }
    
    if(low==h+1) return high;
    if(high==l-1) return low;
    
    return _abs(target-num[low]) < _abs(target-num[high]) ? low:high;
    
}

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        int ret ;
        int flag = 0;
        int N = num.size();
        for(int i=0;i<N;i++){
            if(i!=0&&num[i]==num[i-1]) continue;
            for(int j=i+1;j<N;j++){
                if(j!=i+1&&num[j]==num[j-1]) continue;
                
                int t = target-num[i]-num[j];
                
                int ind = find(j+1,N-1,t,num);
                
                if(ind!=-1){
                    if(flag==0 || _abs(num[i]+num[j]+num[ind]-target) < _abs(ret-target)){
                        ret = num[i]+num[j]+num[ind];
                        flag = 1;
                    }
                }
            }
        }
        
        return ret;
    }
};