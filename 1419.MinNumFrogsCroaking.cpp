#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int minNumberOfFrogs(const std::string& croakOfFrogs) {
        std::unordered_map<char, int> index = {{'c', 0}, {'r', 1}, {'o', 2}, {'a', 3}, {'k', 4}};
        std::vector<int> count(5, 0); // For 'c', 'r', 'o', 'a', 'k'

        int frogsInUse = 0;
        int maxFrogs = 0;

        for (char ch : croakOfFrogs) {
            int i = index[ch];
            count[i]++;

            // Check order: each letter must follow its previous one
            if (i > 0 && count[i] > count[i - 1]) {
                return -1; // Invalid sequence
            }

            if (ch == 'c') {
                frogsInUse++;
                maxFrogs = std::max(maxFrogs, frogsInUse);
            } else if (ch == 'k') {
                // A frog finished croaking
                for (int j = 0; j < 5; ++j) count[j]--;
                frogsInUse--;
            }
        }

        // All counts must be zero (all croaks must complete)
        for (int c : count)
            if (c != 0) return -1;

        return maxFrogs;
    }
};
