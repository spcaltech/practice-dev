#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int visiblePoints(std::vector<std::vector<int>>& points, int angle, std::vector<int>& location) {
        std::vector<double> angles;
        int sameLocation = 0;

        for (const auto& point : points) {
            int dx = point[0] - location[0];
            int dy = point[1] - location[1];

            if (dx == 0 && dy == 0) {
                sameLocation++;
            } else {
                double theta = std::atan2(dy, dx) * 180.0 / M_PI;  // radians → degrees
                if (theta < 0) theta += 360.0;
                angles.push_back(theta);
            }
        }

        std::sort(angles.begin(), angles.end());

        // Duplicate angles +360 to handle wrap-around (circular sliding window)
        int n = angles.size();
        for (int i = 0; i < n; ++i)
            angles.push_back(angles[i] + 360.0);

        // Sliding window to find max points in any angle window
        int maxVisible = 0;
        int left = 0;

        for (int right = 0; right < angles.size(); ++right) {
            while (angles[right] - angles[left] > angle) {
                ++left;
            }
            maxVisible = std::max(maxVisible, right - left + 1);
        }

        return maxVisible + sameLocation;
    }
};
