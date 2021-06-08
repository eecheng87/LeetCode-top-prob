class Solution {
public:
    bool isAlpha(char c){
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            return true;
        else 
            return false;
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i <= j){
            if(!isAlpha(s[i])){
                i++;
            }else if(!isAlpha(s[j])){
                j--;
            }else if(tolower(s[i]) != tolower(s[j])){
                return false;
            }else{
                i++, j--;
            }
        }
        return true;
    }
};