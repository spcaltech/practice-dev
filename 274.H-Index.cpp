#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        int h = 0;
        while (h < citations.size() && citations[h] >= h + 1) {
            ++h;
        }
        return h;
    }
};
