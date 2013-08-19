/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(const Interval& a, const Interval& b){ return a.start<b.start;}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ret;
        int n = intervals.size();
        if(n==0) return ret;
        
        sort(intervals.begin(), intervals.end(),cmp);
        int left = intervals[0].start;
        int right = intervals[0].end;
        
        for(int i=1;i<n;i++)
            if(intervals[i].start <= right && right < intervals[i].end){
                right = intervals[i].end;
            }
            else if(intervals[i].start > right){
                ret.push_back(Interval(left,right));
                left = intervals[i].start;
                right = intervals[i].end;
            }
        
        ret.push_back(Interval(left,right));
        
        return ret;
    }
};