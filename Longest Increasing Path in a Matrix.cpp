#include <bits/stdc++.h>
using namespace std;

class Solution {
    int m, n;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> memo;

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (memo[i][j]) return memo[i][j];
        int maxLen = 1;
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x>=0 && x<m && y>=0 && y<n && matrix[x][y] > matrix[i][j]) {
                maxLen = max(maxLen, 1 + dfs(matrix, x, y));
            }
        }
        return memo[i][j] = maxLen;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        memo.assign(m, vector<int>(n, 0));
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {{9,9,4},{6,6,8},{2,1,1}};
    cout << sol.longestIncreasingPath(matrix); // Output: 4
}
