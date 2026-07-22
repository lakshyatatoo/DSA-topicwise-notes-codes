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
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> nums;
        inorder(root, nums);
        int l = 0;
        int r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == k)
            {
                return true;
            }
            else if (sum < k)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return false;
    }
    void inorder(TreeNode *root, vector<int> &nums)
    {
        if (root == nullptr)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
};

// optimal using BSTIterator
class BSTIterator
{
    stack<TreeNode *> st;
    bool reverse = true;

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushA(root);
    }

    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        if (!reverse)
            pushA(temp->right);
        else
            pushA(temp->left);
        return temp->val;
    }

    bool hasNext() { return !st.empty(); }

private:
    void pushA(TreeNode *root)
    {
        while (root)
        {
            st.push(root);
            if (!reverse)
                root = root->left;
            else
                root = root->right;
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        BSTIterator n(root, false);
        BSTIterator b(root, true);
        int i = n.next();
        int j = b.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = n.next();
            else
                j = b.next();
        }
        return false;
    }
};