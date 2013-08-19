#include<algorithm>

struct node{
    int ind,val;
};

bool comp(const node& a, const node & b){return a.val<b.val;}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<node> arr(numbers.size());
        
        for(int i=0;i<numbers.size();i++){
            arr[i].ind = i;
            arr[i].val = numbers[i];
        }
        
        sort(arr.begin(),arr.end(),comp);
        
        vector<int> ret;
        
        int left = 0, right = numbers.size()-1;
        
        while(left < right){
            if( arr[left].val+arr[right].val == target) break;
            else if( arr[left].val +arr[right].val > target) right--;
            else left++;
        }
        
        if(arr[left].ind > arr[right].ind){
            int tmp = left;
            left = right;
            right = tmp;
        }
        ret.push_back(arr[left].ind+1);
        ret.push_back(arr[right].ind+1);
        
        
        return ret;
    }
};