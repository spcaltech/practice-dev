class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int N = nums.size(), n = N / 2;
        vector<int> L(nums.begin(), nums.begin() + n);
        vector<int> R(nums.begin() + n, nums.end());

        auto groupSums = [&](const vector<int>& a) {
            int m = a.size();
            vector<vector<long long>> G(m + 1);
            for (int mask = 0; mask < (1 << m); ++mask) {
                int k = __builtin_popcount((unsigned)mask);
                long long s = 0;
                for (int i = 0; i < m; ++i) if (mask & (1 << i)) s += a[i];
                G[k].push_back(s);
            }
            return G;
        };

        auto left = groupSums(L);
        auto right = groupSums(R);
        for (int k = 0; k <= n; ++k) sort(right[k].begin(), right[k].end());

        long long S = 0;
        for (int x : nums) S += x;
        long long T = S / 2;

        long long best = LLONG_MAX;
        for (int k = 0; k <= n; ++k) {
            auto &A = left[k], &B = right[n - k];
            for (long long x : A) {
                long long need = T - x;
                auto it = lower_bound(B.begin(), B.end(), need);
                if (it != B.end()) best = min(best, llabs(S - 2 * (x + *it)));
                if (it != B.begin()) { --it; best = min(best, llabs(S - 2 * (x + *it))); }
            }
        }
        return (int)best;
    }
};
