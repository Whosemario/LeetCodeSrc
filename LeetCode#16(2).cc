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
    
    return _abs(target-num[low]) <= _abs(target-num[high]) ? low:high;  // use '<' instead of '<=' will be wrong
    
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
        int left = 0, right= N-1;
        while(left+2<=right){
            int ind = find(left+1,right-1,target-num[left]-num[right],num);
            if(flag==0 || _abs(num[left]+num[right]+num[ind]-target) < _abs(ret-target)){
                ret = num[left]+num[right]+num[ind];
                flag = 1;
            }
            
            if(num[left]+num[right]+num[ind] < target) left++;
            else if(num[left]+num[right]+num[ind] > target) right--;
            else break;
        }
        
        return ret;
    }
};