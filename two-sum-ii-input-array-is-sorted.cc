class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size() < 2) {
            return {};
        }
        int start = 0, end = static_cast<int>(numbers.size()) - 1;
        while (start < end) {
            int sum = numbers[start] + numbers[end];
            if (sum == target) {
                return {start + 1, end + 1};
            } else if (sum < target) {
                ++start;
            } else {
                --end;
            }
        }
        return {};
    }
};
