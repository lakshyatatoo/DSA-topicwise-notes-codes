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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inmap;
        for (int i = 0; i < inorder.size(); i++)
        {
            inmap[inorder[i]] = i;
        }
        TreeNode *root = buildo(preorder, 0, preorder.size() - 1, inorder, 0,
                                inorder.size() - 1, inmap);
        return root;
    }
    TreeNode *buildo(vector<int> &preorder, int preStart, int preEnd,
                     vector<int> &inorder, int inStart, int inEnd,
                     unordered_map<int, int> &inmap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inroot = inmap[root->val];
        int numsLeft = inroot - inStart;
        root->left = buildo(preorder, preStart + 1, preStart + numsLeft, inorder, inStart,
                            inroot - 1, inmap);
        root->right = buildo(preorder, preStart + numsLeft + 1, preEnd, inorder, inroot + 1,
                             inEnd, inmap);

        return root;
    }
};