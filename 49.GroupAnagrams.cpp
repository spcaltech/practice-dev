#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<string>> groupAnagrams(std::vector<string>& strs) {
        std::unordered_map<string, vector<string>> anagramMap;

        for (const string& word : strs) {
            string sortedWord = word;
            std::sort(sortedWord.begin(), sortedWord.end());
            anagramMap[sortedWord].push_back(word);
        }

        std::vector<vector<string>> result;
        for (auto& entry : anagramMap) {
            result.push_back(move(entry.second));
        }
        return result;
    }
};
