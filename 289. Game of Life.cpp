class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                for(int k = max(0, i - 1); k < min(n, i + 2); k++){
                    for(int l = max(0, j - 1); l < min(m, j + 2); l++){
                        cnt += (board[k][l] & 0x1);
                    }
                }
                cnt -= board[i][j];
                if(cnt == 3)
                    board[i][j] |= 0x2;
                else if(cnt == 2 && (board[i][j] & 1))
                    board[i][j] |= 0x2;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] >>= 1;
            }
        }
    }
};