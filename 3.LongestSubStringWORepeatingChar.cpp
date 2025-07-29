#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(const std::string& s) {
        std::unordered_map<char, int> lastSeen;
        int maxLen = 0;
        int start = 0;

        for (int end = 0; end < static_cast<int>(s.length()); ++end) {
            char ch = s[end];

            // If the character is in the current window
            if (lastSeen.count(ch) && lastSeen[ch] >= start) {
                start = lastSeen[ch] + 1;
            }

            lastSeen[ch] = end;
            maxLen = std::max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};
