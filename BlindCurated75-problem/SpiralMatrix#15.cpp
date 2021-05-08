class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int l = 0, u = 0, d = n - 1, r = m - 1, index = 0;
        vector<int> res(m * n, 0);
        
        while(l <= r && u <= d){
            for(int c = l; c <= r; c++){
                res[index++] = matrix[u][c];
            }
            if(++u > d)break;
            for(int c = u; c <= d; c++){
                res[index++] = matrix[c][r];
            }
            if(--r < l)break;
            for(int c = r; c >= l; c--){
                res[index++] = matrix[d][c];
            }
            if(--d < u)break;
            for(int c = d; c >= u; c--){
                res[index++] = matrix[c][l];
            }
            if(++l > r)break;
        }
        
        return res;
    }
};