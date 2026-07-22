#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// brute force approach
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        return 1 + max(lh, rh);
    }
    int maxi = INT_MIN;
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        maxi = max(maxi, lh + rh);
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        return max(maxi, max(left, right));
    }
};

// optimal
class Solution
{
public:
    int maxDepth(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;
        int lh = maxDepth(root->left, maxi);
        int rh = maxDepth(root->right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int maxi = 0;
        maxDepth(root, maxi);
        return maxi;
    }
};