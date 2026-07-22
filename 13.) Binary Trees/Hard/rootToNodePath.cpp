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
    bool path(TreeNode *root, int target, vector<int> &ans)
    {
        if (root == nullptr)
            return false;
        ans.push_back(root->val);
        if (root->val == target)
            return true;

        if (path(root->left, target, ans) || path(root->right, target, ans))
            return true;
        ans.pop_back();
        return false;
    }
    vector<int> getPath(TreeNode *root, int target)
    {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        path(root, target, ans);
        return ans;
    }
};