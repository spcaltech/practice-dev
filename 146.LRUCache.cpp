#include <iostream>
#include <list>
#include <unordered_map>

class LRUCache {
private:
    int capacity;
    // Doubly linked list: stores {key, value}
    std::list<std::pair<int, int>> lru;
    // Map: key -> iterator in the list
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;

        // Move to front (most recently used)
        lru.splice(lru.begin(), lru, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if (it != cache.end()) {
            // Update existing and move to front
            it->second->second = value;
            lru.splice(lru.begin(), lru, it->second);
        } else {
            // Evict if needed
            if (lru.size() == capacity) {
                int evictKey = lru.back().first;
                lru.pop_back();
                cache.erase(evictKey);
            }
            // Insert new
            lru.emplace_front(key, value);
            cache[key] = lru.begin();
        }
    }

    void print() {
        std::cout << "Cache (MRU → LRU): ";
        for (auto& p : lru)
            std::cout << "[" << p.first << ":" << p.second << "] ";
        std::cout << "\n";
    }
};
