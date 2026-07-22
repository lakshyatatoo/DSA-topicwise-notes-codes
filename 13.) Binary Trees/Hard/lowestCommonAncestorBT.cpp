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
    vector<TreeNode *> ans1, ans2;
    bool path(TreeNode *root, TreeNode *target, vector<TreeNode *> &ans)
    {
        if (root == nullptr)
            return false;
        ans.push_back(root);
        if (root == target)
            return true;

        if (path(root->left, target, ans) || path(root->right, target, ans))
            return true;
        ans.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        path(root, p, ans1);
        path(root, q, ans2);
        TreeNode *lca = nullptr;
        for (int i = 0; i < min(ans1.size(), ans2.size()); i++)
        {
            if (ans1[i] == ans2[i])
                lca = ans1[i];
            else
                break;
        }
        return lca;
    }
};

// optimal
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL || root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
            return root;
    }
};