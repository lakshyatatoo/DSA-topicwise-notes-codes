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

// iterative approach
class Solutionx
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        while (root)
        {
            if (root->val < p->val && root->val < q->val)
                root = root->right;
            else if (root->val > p->val && root->val > q->val)
                root = root->left;
            else
                break;
        }
        return root;
    }
};

// recursive approach
class Solutiony
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;
        int cur = root->val;
        if (cur < p->val && cur < q->val)
            return lowestCommonAncestor(root->right, p, q);
        if (cur > p->val && cur > q->val)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};