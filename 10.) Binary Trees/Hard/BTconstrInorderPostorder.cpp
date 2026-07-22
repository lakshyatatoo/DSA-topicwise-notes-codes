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
    TreeNode *buildo(vector<int> &postorder, int ps, int pe,
                     vector<int> &inorder, int is, int ie,
                     unordered_map<int, int> &im)
    {
        if (ps > pe || is > ie)
            return nullptr;
        int ir = im[postorder[pe]];
        int numsLeft = ir - is;
        TreeNode *root = new TreeNode(postorder[pe]);
        root->left =
            buildo(postorder, ps, ps + numsLeft - 1, inorder, is, ir - 1, im);
        root->right =
            buildo(postorder, ps + numsLeft, pe - 1, inorder, ir + 1, ie, im);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> im;
        for (int i = 0; i < inorder.size(); i++)
        {
            im[inorder[i]] = i;
        }
        TreeNode *root = buildo(postorder, 0, postorder.size() - 1, inorder, 0,
                                inorder.size() - 1, im);
        return root;
    }
};