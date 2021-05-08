/* not best solution, ref: https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { 
        int n = matrix.size(), begin = 0, tmp;
        for(int i = n - 1; i >= 1; i--, begin++){
            for(int j = begin; j < i; j++){
                int r = begin, c = j;
                tmp = matrix[r][c];
                matrix[r][c] = matrix[-c + n - 1][r];
                matrix[-c + n - 1][r] = matrix[-r + n - 1][-c + n - 1];
                matrix[-r + n - 1][-c + n - 1] = matrix[c][-r + n - 1];           
                matrix[c][-r + n - 1] = tmp;
            }
        }
    }
};