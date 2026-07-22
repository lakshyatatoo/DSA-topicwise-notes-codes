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

// brute
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lv = max(maxDepth(root->left), 0);
        int rv = max(maxDepth(root->right), 0);
        return root->val + max(lv, rv);
    }
    int maxi = INT_MIN;
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lv = max(0, maxDepth(root->left));
        int rv = max(0, maxDepth(root->right));
        maxi = max(maxi, lv + rv + root->val);
        int lh = maxPathSum(root->left);
        int rh = maxPathSum(root->right);

        return max(maxi, max(lh, rh));
    }
};

// optimal
class Solution
{
public:
    int solve(TreeNode *root, int &maxi)
    {
        if (root == nullptr)
            return 0;
        int lv = max(0, solve(root->left, maxi));
        int rv = max(0, solve(root->right, maxi));
        maxi = max(maxi, root->val + (lv + rv));
        return root->val + max(lv, rv);
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};