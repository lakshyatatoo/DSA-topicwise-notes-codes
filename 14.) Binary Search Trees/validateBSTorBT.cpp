#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

// brute froce tc=O(n) sc=O(n)
class Solution
{
public:
    bool valid(TreeNode *root, long long &prev)
    {
        if (root == nullptr)
            return true;
        if (!valid(root->left, prev))
            return false;
        if (root->val <= prev)
            return false;
        prev = root->val;
        return valid(root->right, prev);
    }
    bool isValidBST(TreeNode *root)
    {
        long long prev = LONG_MIN;
        return valid(root, prev);
    }
};

// better/optimal
// range method or morris inrodere traversal
// tc=O(n) sc=O(1)
class Solution
{
public:
    bool valid(TreeNode *root, long long mnv, long long mxv)
    {
        if (root == nullptr)
            return true;

        if (root->val <= mnv || root->val >= mxv)
            return false;
        return valid(root->left, mnv, root->val) && valid(root->right, root->val, mxv);
    }
    bool isValidBST(TreeNode *root)
    {
        long long mnv = LONG_MIN;
        long long mxv = LONG_MAX;
        return valid(root, mnv, mxv);
    }
};