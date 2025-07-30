#include <queue>

class MedianFinder {
private:
    std::priority_queue<int> maxHeap; // Left half (max heap)
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Right half (min heap)

public:
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);

        // Maintain order: maxHeap's top must be ≤ minHeap's top
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Balance the size: maxHeap can be larger by 1
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() > minHeap.size())
            return maxHeap.top();  // Odd count
        else
            return (maxHeap.top() + minHeap.top()) / 2.0;  // Even count
    }
};
