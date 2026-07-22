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

class Solution
{
public:
    void solve(TreeNode *node, int level, vector<int> &ans)
    {
        if (node == nullptr)
            return;
        if (level == ans.size())
        {
            ans.push_back(node->val);
        }
        solve(node->right, level + 1, ans);
        solve(node->left, level + 1, ans);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        solve(root, 0, ans);
        return ans;
    }
};