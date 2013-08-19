class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = height.size();
        if(N==0) return 0;
        
        vector<int> dpLeft(N);
        vector<int> dpRight(N);
        
        dpLeft[0]=1;
        for(int i=1;i<N;i++){
            int j = i-1;
            while(j>=0 && height[j]>=height[i]){
                j=j-dpLeft[j];
            }
            dpLeft[i]=i-j;
        }
        
        dpRight[N-1]=1;
        for(int i=N-2;i>=0;i--){
            int j=i+1;
            while(j<N && height[j]>=height[i])
                j=j+dpRight[j];
            dpRight[i]=j-i;
        }
        
        int ret = 0;
        for(int i=0;i<N;i++){
            if(height[i]*(dpLeft[i]+dpRight[i]-1) > ret)
                ret = height[i]*(dpLeft[i]+dpRight[i]-1);
        }
        
        return ret;
    }
};