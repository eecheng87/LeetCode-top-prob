class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() < 2)return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        int begin = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] > end){
                res.push_back({begin, end});
                begin = intervals[i][0];
                end = intervals[i][1];
            }else{
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back({begin, end});
        return res;
    }
};