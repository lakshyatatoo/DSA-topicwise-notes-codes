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

// basic check if follows gthe property or not go below for how to make a bianry tree that follows this property
class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (root->left == NULL && root->right == nullptr)
            return true;
        int total = 0;
        if (root->left)
            total += root->left->val;
        if (root->right)
            total += root->right->val;
        return ((root->val == total) && checkTree(root->left) &&
                checkTree(root->right));
    }
};

// making a binary tree that follows the property
class Solution
{
public:
    void checkTree(TreeNode *root)
    {
        if (root == nullptr)
            return;
        int child = 0;
        if (root->left)
            child += root->left->val;
        if (root->right)
            child += root->right->val;
        if (child >= root->val)
        {
            root->val = child;
        }
        else
        {
            if (root->left)
                root->left->val = root->val;
            if (root->right)
                root->right->val = root->val;
        }
        checkTree(root->left);
        checkTree(root->right);

        int total = 0;
        if (root->left)
            total += root->left->val;
        if (root->right)
            total += root->right->val;
        if (root->left || root->right)
            root->val = total;
    }
};
