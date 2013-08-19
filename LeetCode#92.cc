class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = prices.size();
        if(size <=1) return 0;
        
        int _min = prices[0];
        int ret = 0;
        vector<int> dp1(size,0);
        
        for(int i=1;i<size;i++){
            if(prices[i] < _min) _min = prices[i];
            if(prices[i]-_min > ret) ret=prices[i]-_min;
            dp1[i]=ret;
        }
        
        int _max = prices[size-1];
        ret = 0;
        vector<int> dp2(size,0);
        
        for(int i=size-2;i>=0;i--){
            if(prices[i] > _max) _max=prices[i];
            if(_max-prices[i] > ret) ret = _max-prices[i];
            dp2[i]=ret;
        }
        
        ret = 0;
        
        ret = dp1[size-1];
        
        for(int i=1;i<size-1;i++)
            if(dp1[i]+dp2[i+1] > ret)
                ret = dp1[i]+dp2[i+1];
                
        return ret;
    }
};