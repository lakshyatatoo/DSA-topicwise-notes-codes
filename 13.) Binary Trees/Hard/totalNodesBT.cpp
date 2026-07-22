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

// brute
class Solution
{
public:
    void count(TreeNode *root, int &cnt)
    {
        if (root == nullptr)
            return;
        cnt++;
        count(root->left, cnt);
        count(root->right, cnt);
    }
    int countNodes(TreeNode *root)
    {
        int cnt = 0;
        count(root, cnt);
        return cnt;
    }
};

// optimal
class Solution
{
public:
    int findLeft(TreeNode *node)
    {
        int h = 0;
        while (node)
        {
            h++;
            node = node->left;
        }
        return h;
    }
    int findRight(TreeNode *node)
    {
        int h = 0;
        while (node)
        {
            h++;
            node = node->right;
        }
        return h;
    }
    int countNodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = findLeft(root);
        int rh = findRight(root);

        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};