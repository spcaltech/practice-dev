#include <vector>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int write = 0;  // Position to write the compressed result
        int read = 0;   // Position to read input

        while (read < chars.size()) {
            char current = chars[read];
            int count = 0;

            // Count consecutive characters
            while (read < chars.size() && chars[read] == current) {
                ++read;
                ++count;
            }

            // Write character
            chars[write++] = current;

            // Write count if > 1
            if (count > 1) {
                for (char c : std::to_string(count)) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};
