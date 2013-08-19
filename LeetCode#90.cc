class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = prices.size();
        
        if(size==0) return 0;
        
        int ret = 0;
        
        int _min = prices[0];
        
        for(int i=1;i<size;i++){
            if(prices[i]<_min) _min = prices[i];
            else if(prices[i]-_min > ret) 
                    ret = prices[i]-_min;
        }
        
        return ret;
    }
};