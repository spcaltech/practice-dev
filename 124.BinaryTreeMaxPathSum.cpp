#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:
    int maxGain(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        // Max path on the left/right — ignore negatives
        int left = std::max(0, maxGain(node->left, maxSum));
        int right = std::max(0, maxGain(node->right, maxSum));

        // Max path through this node
        int currentPath = node->val + left + right;

        // Update global max if needed
        maxSum = std::max(maxSum, currentPath);

        // Return max gain if continue the same path
        return node->val + std::max(left, right);
    }
};
