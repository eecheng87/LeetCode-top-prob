class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() == 0 || t.size() == 0)return "";
        vector<int> remain(128, 0);
        int n = t.size(), start = 0, end = 0, range = 10e6;
        int remaining = n, offset, res_start;
        for(int i = 0; i < n; i++){
            remain[t[i]]++;
        }
        while(start < s.size() && end <= s.size()){
            if(remaining == 0){
                if(range > end - start){
                    range = end - start;
                    res_start = start;
                }
                remain[s[start++]]++;
                if(remain[s[start - 1]] > 0)remaining++;
            }else{
                if(remain[s[end]] > 0){
                    remaining--;  
                }
                remain[s[end++]]--;  
            }
        }
        return range == 10e6 ? "" : s.substr(res_start, range);
    }
};