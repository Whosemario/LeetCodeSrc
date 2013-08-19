int find(int low,int high,int target,vector<int>& num){
    
    while(low<=high){
        int mid = (low+high)/2;
        if(num[mid]==target) return mid;
        else if(num[mid]>target) high = mid-1;
        else low = mid+1;
    }
    
    return -1;
}

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(),num.end());
        
        vector<vector<int> > ret ;
        
        int N = num.size();
        if(N<3) return ret;
        
        
        for(int i=0;i<N;i++){
            if(i!=0&&num[i]==num[i-1]) continue;
            for(int j=i+1;j<N;j++){
                if(j!=i+1&&num[j]==num[j-1]) continue;
                int target = -num[i]-num[j];
                int ind = find(j+1,N-1,target,num);
                if(ind!=-1){
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[ind]);
                    ret.push_back(tmp);
                }
            }
        }
        
        return ret;
    }
};