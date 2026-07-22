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

class Solution
{
public:
    TreeNode *connect(TreeNode *root)
    {
        if (!root->left)
            return root->right;
        else if (!root->right)
            return root->left;

        TreeNode *rc = root->right;
        TreeNode *lr = findLastRight(root->left);
        lr->right = rc;
        return root->left;
    }
    TreeNode *findLastRight(TreeNode *root)
    {
        while (root->right)
        {
            root = root->right;
        }
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return root;
        if (root->val == key)
            return connect(root);
        TreeNode *pogo = root;
        while (root)
        {
            if (key > root->val)
            {
                if (root->right && root->right->val == key)
                {
                    root->right = connect(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
            else
            {
                if (root->left && root->left->val == key)
                {
                    root->left = connect(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
        }
        return pogo;
    }
};