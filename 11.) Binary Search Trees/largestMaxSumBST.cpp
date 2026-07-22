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

// brute tle.
// change the code to +1 at each node to make it largest size of bst
class Solution
{
    long long maxSum = 0;

private:
    bool valid(TreeNode *root, long long mnv, long long mxv, long long &sum)
    {
        if (root == nullptr)
            return true;
        if (root->val <= mnv || root->val >= mxv)
            return false;
        sum += root->val;
        return valid(root->left, mnv, root->val, sum) &&
               valid(root->right, root->val, mxv, sum);
    }
    void check(TreeNode *root)
    {
        if (root == nullptr)
            return;
        check(root->left);
        long long sum = 0;
        if (valid(root, LONG_MIN, LONG_MAX, sum))
            maxSum = max(sum, maxSum);
        check(root->right);
    }

public:
    int maxSumBST(TreeNode *root)
    {
        check(root);
        return maxSum;
    }
};

// optimal for size of bst gfg
class NodeValue
{
public:
    int maxNode, minNode, size;
    NodeValue(int minNode, int maxNode, int size)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->size = size;
    }
};
class Solution
{
public:
    NodeValue helper(Node *root)
    {
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0); // we check for null of left we send max as min and min as max so that it can be valid for parent node
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        if (left.maxNode < root->data && root->data < right.minNode)
        {
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode), left.size + right.size + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.size, right.size));
    }
    int largestBst(Node *root)
    {
        return helper(root).size;
    }
};

// optimal for sum of bst leetcode
// isbst can be removed and it would make no difference as we are returning INT_MIN and INT_MAX for invalid bst so it will be invalid for parent node
class NodeValue
{
public:
    int maxNode, minNode, sum;
    bool isBST;
    NodeValue(int minNode, int maxNode, int sum, bool isBST)
    {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->sum = sum;
        this->isBST = isBST;
    }
};
class Solution
{
public:
    NodeValue helper(TreeNode *root, int &maxSum)
    {
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0, true); // we check for null of left we send max as min and min as max so that it can be valid for parent node
        }
        auto left = helper(root->left, maxSum);
        auto right = helper(root->right, maxSum);
        if (left.isBST && right.isBST && left.maxNode < root->val && root->val < right.minNode)
        {
            int sum = left.sum + right.sum + root->val;
            maxSum = max(maxSum, sum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), sum, true);
        }
        return NodeValue(INT_MIN, INT_MAX, max({0, left.sum, right.sum}), false);
    }
    int maxSumBST(TreeNode *root)
    {
        int maxSum = 0;
        helper(root, maxSum);
        return maxSum;
    }
};