class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = prices.size();
        if(size<=1) return 0;
        
        int left=0;
        int ret = 0;
        
        for(int i=1;i<size;i++){
            if((i==size-1 || prices[i] > prices[i+1]) && prices[i]>=prices[i-1]){
                if(left!=-1) ret+=prices[i]-prices[left];
                left=-1;
                continue;
            }
            if(left==-1 || prices[i] < prices[i-1]){
                left = i;
            }
        }
        
        return ret;
    }
};