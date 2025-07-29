#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string makeLargestSpecial(string s) {
        std::vector<string> subs;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); ++i) {
            count += (s[i] == '1') ? 1 : -1;

            // Found a primitive special string
            if (count == 0) {
                // Recursively sort the inside
                string inner = makeLargestSpecial(s.substr(start + 1, i - start - 1));
                subs.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        // Sort in descending lex order
        std::sort(subs.begin(), subs.end(), greater<>());

        std::string result;
        for (const string& sub : subs)
            result += sub;
        return result;
    }
};
