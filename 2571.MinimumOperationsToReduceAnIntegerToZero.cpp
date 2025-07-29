#include <queue>
#include <unordered_set>
#include <climits>

class Solution {
public:
    int minOperations(int n) {
        std::queue<long long> q;
        std::unordered_set<long long> visited;

        q.push(n);
        visited.insert(n);
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                long long curr = q.front(); q.pop();
                if (curr == 0) return steps;

                for (int i = 0; i < 32; ++i) {
                    long long p = 1LL << i;

                    long long add = curr + p;
                    if (add <= INT_MAX && visited.insert(add).second)
                        q.push(add);

                    long long sub = curr - p;
                    if (sub >= 0 && visited.insert(sub).second)
                        q.push(sub);
                }
            }
            ++steps;
        }
        return -1;
    }
};
