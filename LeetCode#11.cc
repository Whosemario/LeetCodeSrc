#define _min(x,y) ((x)<(y)?(x):(y))

class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = height.size();
        
        if(N<=1) return 0;
        
        int left = 0, right = N-1;
        int ret = 0;
        while(left <= right){
            if(_min(height[left],height[right])*(right-left) > ret)
                ret = _min(height[left],height[right])*(right-left);
            if(height[left]<=height[right]) left++;
            else right--;
        }
        
        return ret;
    }
};