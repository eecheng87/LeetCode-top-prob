class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool r = false, c = false; /* flag for first row and col */
        for(int i = 0; i < matrix[0].size(); i++)
            if(!matrix[0][i])
                r = true;
        for(int i = 0; i < matrix.size(); i++)
            if(!matrix[i][0])
                c = true;
        
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
        }
        if(r)
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[0][i] = 0;
        if(c)
            for(int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
    }
};