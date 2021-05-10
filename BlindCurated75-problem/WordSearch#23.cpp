class Solution {
public:
    bool dfs(vector<vector<char>>& board, int x, int y, string w, int index){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == 0)
            return false;
        if(board[x][y] != w[index])
            return false;
        else if(index == w.size() - 1)
            return true;
        else{
            board[x][y] = 0;
            if(dfs(board, x + 1, y, w, index + 1) ||
            dfs(board, x - 1, y, w, index + 1) ||
            dfs(board, x, y + 1, w, index + 1) ||
            dfs(board, x, y - 1, w, index + 1))
                return true;
            board[x][y] = w[index];
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                if(dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};