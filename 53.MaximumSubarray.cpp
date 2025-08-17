class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long cur = nums[0], ans = nums[0];
        for (int i = 1; i < (int)nums.size(); ++i) {
            cur = max<long long>(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }
        return (int)ans;
    }
};
