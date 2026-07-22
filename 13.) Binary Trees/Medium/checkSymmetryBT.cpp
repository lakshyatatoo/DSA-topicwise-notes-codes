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

// optimal
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return root == nullptr || isMirror(root->left, root->right);
    }
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr || right == nullptr)
            return left == right;

        if (left->val != right->val)
            return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};