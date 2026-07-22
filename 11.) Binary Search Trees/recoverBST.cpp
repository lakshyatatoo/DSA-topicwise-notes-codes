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
private:
    void inorderF(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        inorderF(root->left, nums);
        nums.push_back(root->val);
        inorderF(root->right, nums);
    }
    void inorderS(TreeNode *root, vector<int> &nums, int &i)
    {
        if (root == nullptr)
            return;
        inorderS(root->left, nums, i);
        if (i < nums.size() && root->val != nums[i])
            root->val = nums[i];
        i++;
        inorderS(root->right, nums, i);
    }

public:
    void recoverTree(TreeNode *root)
    {
        vector<int> ans;
        inorderF(root, ans);
        sort(ans.begin(), ans.end());
        int i = 0;
        inorderS(root, ans, i);
    }
};

// optimal
class Solution
{
    TreeNode *first, *middle, *prev, *last;

private:
    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;
        inorder(root->left);
        if (prev != nullptr && root->val < prev->val)
        {
            if (first == nullptr)
            {
                first = prev;
                middle = root;
            }
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};