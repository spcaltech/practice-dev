class SparseVector {
public:
    vector<pair<int,int>> nz; // (index, value)

    SparseVector(vector<int> &nums) {
        nz.reserve(nums.size());
        for (int i = 0; i < (int)nums.size(); ++i)
            if (nums[i] != 0) nz.emplace_back(i, nums[i]);
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        const auto &a = nz, &b = vec.nz;
        int i = 0, j = 0;
        long long res = 0;
        while (i < (int)a.size() && j < (int)b.size()) {
            if (a[i].first == b[j].first) {
                res += 1LL * a[i].second * b[j].second;
                ++i; ++j;
            } else if (a[i].first < b[j].first) {
                ++i;
            } else {
                ++j;
            }
        }
        return (int)res;
    }
};
