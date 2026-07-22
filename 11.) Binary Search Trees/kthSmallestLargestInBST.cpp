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

// brute;
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;
        inorder(root, ans);
        sort(ans.begin(), ans.end());
        int cnt = 0;
        for (int x : ans)
        {
            cnt++;
            if (cnt == k)
                return x;
        }
        return -1;
    }
};

// better
class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> ans;
        inorder(root, ans);
        int cnt = 0;
        for (int x : ans)
        {
            cnt++;
            if (cnt == k)
                return x;
        }
        return -1;
    }
};

// optimal (largest + smallest)
class Solution
{
public:
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans1 = 0;
        int n = countNodes(root);
        n = n - k + 1;
        int ans2 = 0;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left == nullptr)
            {
                k--;
                n--;
                if (k == 0)
                    ans1 = cur->val;
                if (n == 0)
                    ans2 = cur->val;
                cur = cur->right;
            }
            else
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                if (prev->right == nullptr)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    prev->right = nullptr;
                    k--;
                    n--;
                    if (k == 0)
                        ans1 = cur->val;
                    if (n == 0)
                        ans2 = cur->val;
                    cur = cur->right;
                }
            }
        }
        return ans1;
    }
};