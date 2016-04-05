class Solution {
public:
    void reverseWords(string &s) {
        if (s.length() < 2) {
            return;
        }
        reverse(s.begin(), s.end());
        auto itor = s.begin();
        while (itor != s.end()) {
            if (*itor == ' ') {
                ++itor;
                continue;
            }
            auto end = itor;
            while (end != s.end() && *end != ' ') {
                ++end;
            }
            reverse(itor, end);
            // bug: itor = end;
            itor = end;
        }
    }
};
