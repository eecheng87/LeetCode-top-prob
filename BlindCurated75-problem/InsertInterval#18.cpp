class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int begin, end, i;
        vector<vector<int>> res;
        if(intervals.size() < 1){
            res.push_back(newInterval);
            return res;
        }
        for(i = 0; i < intervals.size(); i++){
            if(newInterval[0] <= intervals[i][0]){
                break;
            }
        }
        intervals.insert(intervals.begin() + i, newInterval);
        begin = intervals[0][0];
        end = intervals[0][1];
        for(i = 1; i < intervals.size(); i++){
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