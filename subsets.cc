class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        search(nums, result, path, 0);
        return result;
    }
private:
    void search(vector<int>& nums, vector<vector<int>>& result, vector<int>& path, int pos) {
        result.emplace_back(path);
        if (pos == nums.size()) {
            return;
        }
        for (int i = pos; i < nums.size(); ++i) {
            path.emplace_back(nums[i]);
            search(nums, result, path, i + 1);
            path.pop_back();
        }
    }
};
