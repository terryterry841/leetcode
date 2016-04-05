class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int height = grid.size();
        int width = grid[0].size();
        int result = 0;
        for (int x = 0; x < height; ++x) {
            for (int y = 0; y < width; ++y) {
                if (grid[x][y] == '1') {
                    dfsfill(grid, x, y);
                    ++result;
                }
            }
        }
        return result;
    }
private:
    void dfsfill(vector<vector<char>>& grid, int x, int y) {
        int height = grid.size();
        int width = grid[0].size();
        if (x < 0 || x >= height || y < 0 || y >= width ||
            grid[x][y] != '1') {
            return;        
        }
        grid[x][y] = '$';
        static const vector<int> dx{0, 0, 1, -1};
        static const vector<int> dy{1, -1, 0, 0};
        for (int i = 0; i < dx.size(); ++i) {
            dfsfill(grid, x + dx[i], y + dy[i]);
        }
    }
};
