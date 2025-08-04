#include <string>
#include <sstream>
#include <queue>

class Codec {
public:
    // Serialize using preorder traversal
    std::string serialize(TreeNode* root) {
        if (!root) return "null";
        return std::to_string(root->val) + "," +
               serialize(root->left) + "," +
               serialize(root->right);
    }

    // Helper function to split string into tokens
    void split(const std::string& s, std::queue<std::string>& tokens) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, ',')) {
            tokens.push(item);
        }
    }

    TreeNode* buildTree(std::queue<std::string>& tokens) {
        if (tokens.empty()) return nullptr;

        std::string val = tokens.front();
        tokens.pop();

        if (val == "null") return nullptr;

        TreeNode* node = new TreeNode(std::stoi(val));
        node->left = buildTree(tokens);
        node->right = buildTree(tokens);
        return node;
    }

    // Deserialize string back to tree
    TreeNode* deserialize(const std::string& data) {
        std::queue<std::string> tokens;
        split(data, tokens);
        return buildTree(tokens);
    }
};
