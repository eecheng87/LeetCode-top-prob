class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> mp(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++)
            mp[i][0] = 1;
        for(int i = 0; i < n; i++)
            mp[0][i] = 1;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                mp[i][j] = mp[i - 1][j] + mp[i][j - 1];
        return mp[m - 1][n - 1];
    }
};