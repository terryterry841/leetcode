class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        }
        int width = matrix.size();
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < width; ++i) {
            // bug: for (int j = i + 1; j < width; ++j) {
            for (int j = i + 1; j < width; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
