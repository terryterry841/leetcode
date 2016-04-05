class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int maxLength = 0, resultStart = 0;
        int length = s.length();
        for (int i = 0; i < length; ) {
            int start = i, end = i;
            while (0 <= start - 1 && s[start - 1] == s[i]) {
                --start;
            }
            while (end + 1 < length && s[end + 1] == s[i]) {
                ++end;
            }
            i = end + 1;
            while (0 <= start - 1 && end + 1 < length &&
                s[start - 1] == s[end + 1]) {
                --start;
                ++end;
            }
            if (end - start + 1 > maxLength) {
                maxLength = end - start + 1;
                resultStart = start;
            }
            // bug: i = end + 1; 不能写在最后
        }
        return s.substr(resultStart, maxLength);
    }
};
