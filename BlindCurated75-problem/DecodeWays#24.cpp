class Solution {
public:
    int numDecodings(string s) {
        if(s.size() < 1 || s[0] == '0')return 0;
        int dp[s.size() + 1];
        // dp[i] means # of method compose length i string
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i = 2; i <= s.size(); i++){
            int digit = s[i - 2] - '0';
            digit = digit * 10 + s[i - 1] - '0';
            if(digit == 0 || (s[i - 1] == '0' && digit > 26))
                return 0;
            else if(s[i - 1] == '0')
                dp[i] = dp[i - 2];
            else if((digit > 0 && digit < 10) || (digit > 26))
                dp[i] = dp[i - 1];
            else if(digit > 10 && digit < 27)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                return 0;
        }
        
        return dp[s.size()];
    }
};