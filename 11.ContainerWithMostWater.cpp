#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int max_water = 0;
        int left = 0, right = height.size() - 1;

        while (left < right) {
            int h = std::min(height[left], height[right]);
            int w = right - left;
            max_water = std::max(max_water, h * w);

            // Move the shorter line inward
            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_water;
    }
};
