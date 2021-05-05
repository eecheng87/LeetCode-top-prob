class Solution {
public:
string longestPalindrome(string s) {
    if(s.size() <= 1)
        return s;
    int len = s.size(), ans_start = 0, ans_size = 1;
    bool dp[len][len];

    for(int i = 0; i < len; i++)
        dp[i][i] = true;

    for(int i = len - 1; i >= 0; i--){
        for(int j = 1; j < len - i; j++){
            int k = i + j;
            if(j == 1)
                dp[i][k] = (s[i] == s[k]);
            else
                dp[i][k] = (s[i] == s[k] && dp[i + 1][k - 1]);

            if(dp[i][k] && j + 1 > ans_size){
                ans_start = i;
                ans_size = j + 1;
            }

        }
    }
    return s.substr(ans_start, ans_size);
}
};