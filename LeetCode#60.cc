class Solution {
public:
    bool searchMatrix(vector<vector<int> > &mat, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = mat.size();
        if(n==0) return false;
        int m = mat[0].size();
        if(m==0) return false;
        
        int row = -1;
        {
            int low = 0,high = n-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(mat[mid][0]==target) return true;
                else if(target > mat[mid][0]) low = mid+1;
                else high = mid-1;
            }
            if(high==-1) return false;
            row = high;
        }
        
        {
            int low = 0,high = m-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(mat[row][mid]==target) return true;
                else if(target > mat[row][mid]) low = mid+1;
                else high = mid-1;
            }
        }
        
        return false;
    }
};