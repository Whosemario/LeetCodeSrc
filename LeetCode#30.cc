class Solution {
private:
    int getLow(int A[], int n, int target){
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target<=A[mid]) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
    
    int getHigh(int A[], int n, int target){
        int low = 0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(target >= A[mid]) low = mid+1;
            else high = mid-1;
        }
        return high;
    }
    
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        if(n==0){
            ret.push_back(-1);
            ret.push_back(-1);
            return ret;
        }
        int left = getLow(A,n,target);
        int right = getHigh(A,n,target);
        if(left!=-1&&A[left]==target&&right!=-1&&A[right]==target){
            ret.push_back(left);
            ret.push_back(right);
        }
        else{
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};