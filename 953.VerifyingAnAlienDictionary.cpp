#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAlienSorted(std::vector<std::string>& words, std::string order) {
        std::unordered_map<char, int> rank;
        for (int i = 0; i < order.size(); ++i) {
            rank[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; ++i) {
            if (!inCorrectOrder(words[i], words[i + 1], rank)) {
                return false;
            }
        }
        return true;
    }

    bool inCorrectOrder(const std::string& word1, const std::string& word2,
                        const std::unordered_map<char, int>& rank) {
        int len = std::min(word1.size(), word2.size());
        for (int i = 0; i < len; ++i) {
            if (word1[i] != word2[i]) {
                return rank.at(word1[i]) < rank.at(word2[i]);
            }
        }
        return word1.size() <= word2.size();
    }
};
