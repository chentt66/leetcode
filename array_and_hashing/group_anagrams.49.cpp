// O(n*klogk) time
// O(n*k) space
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<string>> groups;
        for (const string& word: strs) {
            // O(k)
            string key = word; // eat
            // O(k*logk)
            sort(key.begin(), key.end()); // aet
            // O(k) for hashing the key + O(1) amortized for push_back
            groups[key].push_back(word); 
        }
        std::vector<std::vector<string>> result;
        for (std::pair<const std::string, std::vector<std::string>>& pair: groups) {
            result.push_back(pair.second); // O(n⋅k) total — copies all strings
        }
        return result;
    }
};
