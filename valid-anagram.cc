class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        vector<int> count_s(26);
        for (const auto& c : s) {
            ++count_s[c - 'a'];
        }
        for (const auto& c : t) {
            if (--count_s[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
