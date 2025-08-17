class Solution {
public:
    int minOperations(int n) {
        int ans = 0;
        while (n > 0) {
            // power of two check: x & (x-1) == 0
            if ((n & (n - 1)) == 0) return ans + 1;

            // highest power of two <= n
            int p = 31 - __builtin_clz(n);
            int lo = 1 << p;
            int hi = lo << 1;

            // move to the nearer power of two
            if (n - lo <= hi - n) n -= lo;
            else                  n = hi - n;

            ++ans;
        }
        return ans;
    }
};
