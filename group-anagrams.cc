class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty()) {
            return {};
        }
        unordered_map<string, vector<string>> hashmap;
        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hashmap[key].emplace_back(str);
        }
        vector<vector<string>> result;
        for (auto& pair : hashmap) {
            sort(pair.second.begin(), pair.second.end());
            result.emplace_back(move(pair.second));
        }
        return result;
    }
};
