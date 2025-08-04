#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <vector>

class Solution {
public:
    int slidingPuzzle(std::vector<std::vector<int>>& board) {
        std::string start, target = "123450";
        for (const auto& row : board) {
            for (int num : row)
                start += std::to_string(num);
        }

        // Possible moves for each index (0 to 5) on a 2x3 board
        std::vector<std::vector<int>> neighbor = {
            {1, 3},        // 0
            {0, 2, 4},     // 1
            {1, 5},        // 2
            {0, 4},        // 3
            {1, 3, 5},     // 4
            {2, 4}         // 5
        };

        std::queue<std::pair<std::string, int>> q;
        std::unordered_set<std::string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            if (cur == target) return steps;

            int zero_pos = cur.find('0');
            for (int nei : neighbor[zero_pos]) {
                std::string next = cur;
                std::swap(next[zero_pos], next[nei]);

                if (!visited.count(next)) {
                    q.push({next, steps + 1});
                    visited.insert(next);
                }
            }
        }

        return -1;  // impossible
    }
};
