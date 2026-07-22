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

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *temp = root;
        for (int i = 1; i < preorder.size(); i++)
        {
            temp = root;
            while (temp)
            {
                if (preorder[i] < temp->val)
                {
                    if (temp->left)
                    {
                        temp = temp->left;
                    }
                    else
                    {
                        temp->left = new TreeNode(preorder[i]);
                        break;
                    }
                }
                else
                {
                    if (temp->right)
                    {
                        temp = temp->right;
                    }
                    else
                    {
                        temp->right = new TreeNode(preorder[i]);
                        break;
                    }
                }
            }
        }
        return root;
    }
};

// better
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int, int> &mp)
    {
        if (ps > pe || is > ie)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int ir = mp[preorder[ps]];
        int numsLeft = ir - is;
        root->left = buildTree(preorder, ps + 1, ps + numsLeft, inorder, is, ir - 1, mp);
        root->right = buildTree(preorder, ps + numsLeft + 1, pe, inorder, ir + 1, ie, mp);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, mp);
    }
};

// optimal
class Solution
{
public:
    TreeNode *build(vector<int> &preorder, int &i, int bound)
    {
        if (i == preorder.size() || preorder[i] > bound)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};