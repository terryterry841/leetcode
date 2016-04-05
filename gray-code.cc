class Solution {
public:
    // n=0 0
    // n=1 0
    //     1
    // n=2 00
    //     01
    //     11
    //     10
    // n=3 000
    //     001
    //     011
    //     010
    //     110
    //     111
    //     101
    //     100
    vector<int> grayCode(int n) {
        if (n < 0) {
            return {};
        }
        vector<int> result{0};
        for (int i = 0; i < n; ++i) {
            int size = result.size();
            for (int j = size - 1; j >= 0; --j) {
                result.emplace_back(result[j] + (1 << i));  // bug: (i << i)
            }
        }
        return result;
    }
    
    vector<int> grayCodeRecursive(int n) {
        if (n < 0) {
            return {};
        }
        if (n == 0) {
            return {0};
        }
        auto result = grayCodeRecursive(n - 1);
        int size = result.size();
        for (int i = size - 1; i >= 0; --i) {
            result.emplace_back(result[i] + (1 << (n - 1)));  // bug: 1 << (n - 1)
        }
        return result;
    }
};
