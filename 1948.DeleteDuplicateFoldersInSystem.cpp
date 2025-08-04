#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct Folder {
    std::string name;
    std::map<std::string, Folder*> children;
    bool duplicate = false;

    Folder(const std::string& name) : name(name) {}
};

class Solution {
public:
    Folder* root = new Folder("");

    // Build tree from input paths
    void buildTree(const std::vector<std::vector<std::string>>& paths) {
        for (const auto& path : paths) {
            Folder* node = root;
            for (const auto& dir : path) {
                if (!node->children.count(dir)) {
                    node->children[dir] = new Folder(dir);
                }
                node = node->children[dir];
            }
        }
    }

    // Serialization + detect duplicates
    std::unordered_map<std::string, std::vector<Folder*>> subtreeMap;

    std::string serialize(Folder* node) {
        if (node->children.empty()) return "";

        std::vector<std::string> serials;
        for (auto& [name, child] : node->children) {
            serials.push_back(name + "(" + serialize(child) + ")");
        }
        std::sort(serials.begin(), serials.end());
        std::string signature = "";
        for (auto& s : serials) signature += s;

        subtreeMap[signature].push_back(node);
        return signature;
    }

    void markDuplicates() {
        for (auto& [key, nodes] : subtreeMap) {
            if (nodes.size() > 1) {
                for (auto* node : nodes) {
                    node->duplicate = true;
                }
            }
        }
    }

    // Collect paths without duplicates
    void collectPaths(Folder* node, std::vector<std::string>& path, std::vector<std::vector<std::string>>& result) {
        for (auto& [name, child] : node->children) {
            if (!child->duplicate) {
                path.push_back(name);
                result.push_back(path);
                collectPaths(child, path, result);
                path.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> deleteDuplicateFolder(std::vector<std::vector<std::string>>& paths) {
        buildTree(paths);
        serialize(root);
        markDuplicates();

        std::vector<std::vector<std::string>> result;
        std::vector<std::string> path;
        collectPaths(root, path, result);
        return result;
    }
};
