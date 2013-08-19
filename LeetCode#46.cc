/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &ints, Interval newInt) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool isFinish = false;
        int n = ints.size();
        vector<Interval> ret;
        for(int i=0;i<n;i++)
            if(isFinish)
                ret.push_back(ints[i]);
            else{
                if(newInt.start <= ints[i].end){
                    if(newInt.end < ints[i].start){
                        ret.push_back(newInt);
                        ret.push_back(ints[i]);
                        isFinish=true;
                    }
                    else{
                        int left = newInt.start < ints[i].start ? newInt.start:ints[i].start;
                        int right= newInt.end > ints[i].end ? newInt.end : ints[i].end;
                        int j = i+1;
                        while(j<n&&ints[j].start<=right){
                            if(ints[j].end>right) right = ints[j].end;
                            j++;
                        }
                        ret.push_back(Interval(left,right));
                        isFinish=true;
                        i=j-1;
                    }
                }
                else{
                    ret.push_back(ints[i]);
                }
            }
            
            if(!isFinish) ret.push_back(newInt);
            
            return ret;
    }
};