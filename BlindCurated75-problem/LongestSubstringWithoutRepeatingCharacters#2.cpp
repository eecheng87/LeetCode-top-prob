class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0, cur = 0, start = 0;
        for(int i = 0; i < s.size(); i++){
            if(mp.find(s[i]) != mp.end()){
                // repeat
                int j;
                for(j = start; j <= mp[s[i]]; j++){
                    mp.erase(s[j]);
                }
                start = j;
                mp[s[i]] = i;
                ans = max(ans, cur);
                cur = i - j + 1;
            }else{
                // no repeat
                mp[s[i]] = i;
                cur++;
            }
        }
        ans = max(ans, cur);
        return ans;
    }
};
